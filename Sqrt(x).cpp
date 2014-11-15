class Solution {
public:
	int sqrt(int x) {
		double y = x/2.0;
		double gap =  y * y - x;
		while (abs(gap) > 1e-2) {
			
			y = (y + x/y)/2;

			gap = y * y - x;
		}

		return y;
	}
};