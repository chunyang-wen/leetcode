class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        if(s.find("IV")!= string::npos){sum-=2;}
        if(s.find("IX")!= string::npos){sum-=2;}
        if(s.find("XL")!= string::npos){sum-=20;}
        if(s.find("XC")!= string::npos){sum-=20;}
        if(s.find("CD")!= string::npos){sum-=200;}
        if(s.find("CM")!= string::npos){sum-=200;}

        int len = s.size();

        for(int count=0; count < len ;count++){
            if(s[count]=='M') sum+=1000;
            if(s[count]=='D') sum+=500;
            if(s[count]=='C') sum+=100;
            if(s[count]=='L') sum+=50;
            if(s[count]=='X') sum+=10;
            if(s[count]=='V') sum+=5;
            if(s[count]=='I') sum+=1;

     }

   return sum;

}
};