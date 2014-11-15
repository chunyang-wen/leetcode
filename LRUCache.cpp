class LRUCache{
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
		size = 0;
	}

	int get(int key) {
		if (!cache.count(key))
			return -1;

		list<int>::iterator cur = keyQueue.begin();

		while (*cur != key) {
			++cur;
		}

		keyQueue.erase(cur);
		// cur = keyQueue.begin();
		// keyQueue.insert(cur, key);
		keyQueue.push_front(key);

		return cache[key];
	}

	void set(int key, int value) {

		if (cache.count(key) != 0) {
			// update

			list<int>::iterator cur = keyQueue.begin();

			while (*cur != key) {
				++cur;
			}

			keyQueue.erase(cur);
			// cur = keyQueue.begin();
			// keyQueue.insert(cur, key);
			keyQueue.push_front(key);
			cache[key] = value;

			return;
		}

		if (size < capacity) {
			// insert
			cache[key] = value;
			// list<int>::iterator cur = keyQueue.begin();
			// keyQueue.insert(cur, key);
			keyQueue.push_front(key);
			++size;
		}
		else {
			// replace
			int keyDel = keyQueue.back();
			keyQueue.pop_back();
			// list<int>::iterator cur = keyQueue.begin();
			// keyQueue.insert(cur, key);
			cache.erase(keyDel);
			keyQueue.push_front(key);
			cache[key] = value;
		}
	}

private:
	unordered_map<int,int> cache;
	list<int> keyQueue;
	int capacity;
	int size;
};