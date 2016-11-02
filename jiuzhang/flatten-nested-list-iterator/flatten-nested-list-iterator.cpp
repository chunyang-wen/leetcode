/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class NestedIterator {
public:
    stack st;
    NestedIterator(vector &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            st.push(nestedList[i]);
        }
    }

    int next() {
        int ans =  st.top().getInteger();
        st.pop();
        return ans;
    }

    bool hasNext() {
        while (!st.empty()) {
            if (st.top().isInteger()) {
                return true;
            }
            vector  nestedList = st.top().getList();
            st.pop();
            for (int i = nestedList.size() - 1; i >= 0; i--) {
                st.push(nestedList[i]);
            }
        }
        return false;
    }
};

