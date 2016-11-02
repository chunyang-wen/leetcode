/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class KeyValue {
public:
    int key, value;
    KeyValue *next;
    KeyValue(int key, int value) {
        next = NULL;
        this->key = key;
        this->value = value;
    }
    KeyValue() {
        this->next = NULL;
        this->key = 0;
        this->value = 0;
    }
};

class LRUCache{
private:
    void moveToTail(KeyValue *prev) {
        if (prev->next == tail) {
            return;
        }
        
        KeyValue *node = prev->next;
        prev->next = node->next;
        if (node->next != NULL) {
            hash[node->next->key] = prev;
        }
        tail->next = node;
        node->next = NULL;
        hash[node->key] = tail;
        tail = node;
    }
    
public:
    unordered_map hash;
    KeyValue *head, *tail;
    int capacity, size;
    
    LRUCache(int capacity) {
        this->head = new KeyValue(0, 0);
        this->tail = head;
        this->capacity = capacity;
        this->size = 0;
        hash.clear();
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        }
        
        moveToTail(hash[key]);
        return hash[key]->next->value;
    }
    
    void set(int key, int value) {
        if (hash.find(key) != hash.end()) {
            hash[key]->next->value = value;
            moveToTail(hash[key]);
        } else {
            KeyValue *node = new KeyValue(key, value);
            tail->next = node;
            hash[key] = tail;
            tail = node;
            size++;
            if (size > capacity) {
                hash.erase(head->next->key);
                head->next = head->next->next;
                if (head->next != NULL) {
                    hash[head->next->key] = head;
                }
                size--;
            }
        }
    }
};
