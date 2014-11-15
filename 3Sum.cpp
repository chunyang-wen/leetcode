class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > result;
		vector<int> tempResult;
		sort( num.begin(),num.end() );

		int p,q,temp;
		for(int i=0;i<num.size();i++){
			if( i!=0 && num[i]==num[i-1] )continue;     //num 1：only reserve first of all same values  
				int current=num[i];
				p=i+1,q=num.size()-1;

			while(p<q){
				if(p!=i+1 && num[p]==num[p-1] ){        //num 2：only reserve first of all same values 
					p++;
					continue;
				}
				temp=num[p]+num[q];

				if(temp==-current){                 //find
					tempResult.push_back(current);tempResult.push_back(num[p]);tempResult.push_back(num[q]);
					result.push_back(tempResult);
					tempResult.clear();
					p++;q--;
				}else if(temp>-current)q--;       //larger, go left
				else p++;                         //smaller, go right
			}
		}

		return result;  
	}
};