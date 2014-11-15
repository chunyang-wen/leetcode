class Solution {
public:
	string simplifyPath(string path) {
		if (path.size() < 2)
			return path;
		stack<string> st;
		int i = 0;
		int j;
		int len = path.size();
		string str;
		// "/home/../.././abc/./cd/../"
		while (i < len) {
			j = i;
			while (j < len && path[j] != '/')
				++j;

			if (i == j) {
				if (st.empty())
					st.push("/");

				i = j+1;
				continue;
			}

			str = path.substr(i,j-i);
			if (str == "./" || str == ".") {
				i = j+1;
				continue;
			}
			else if (str == "../" || str == "..") {
				if (!st.empty())
					st.pop();
				if (st.empty())
					st.push("/");
			}
			else {
				if (str.empty() && st.empty())
					st.push("/");
				else
					st.push(str);
			}
			i = j+1;
		}
		str = "";
		string tmp;
		if (st.size() == 1)
		    return st.top();
		while (!st.empty()) {
			tmp = st.top();
			reverse(tmp.begin(),tmp.end());
			if (tmp != "/")
			    str += "/";
			str += tmp;
			st.pop();
		}
		reverse(str.begin(),str.end());
		//if (str.size() == 1)
		//     return str;
		// if (str[str.size()-1] == '/')
		    return str.substr(0,str.size()-1);
		// return str;

	}
};