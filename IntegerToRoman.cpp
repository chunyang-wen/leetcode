// Well, we can also use greedy method.
class Solution {
public:
    string intToRoman(int num) {
        string str="";
        int pos = 0;
        while(num) {
            str += intToRomanHelper(num%10,pos);
            ++pos;
            num /= 10;
        }
        reverse(str.begin(),str.end());
        return str;
    }
    
private:
    string intToRomanHelper(int num, int decimalPos) {
        string str;
        switch(decimalPos) {
            case 0:
                switch(num) { // less than 10
                    case 0:
                        return "";break;
                    case 1:
                        str += "I";break;
                    case 2:
                        str += "II";break;
                    case 3:
                        str += "III";break;
                    case 4:
                        str += "VI";break; // IV
                    case 5:
                        str += "V";break;
                    case 6:
                        str += "IV";break; // VI
                    case 7:
                        str += "IIV";break; // VII
                    case 8:
                        str += "IIIV";break; // VIII
                    case 9:
                        str += "XI";break; // IX
                }
                break;
            case 1:
                switch(num) { // less than 100
                    case 0:
                        return "";break;
                    case 1:
                        str += "X";break;
                    case 2:
                        str += "XX";break;
                    case 3:
                        str += "XXX";break;
                    case 4:
                        str += "LX";break; // XL
                    case 5:
                        str += "L";break;
                    case 6:
                        str += "XL";break; // LX
                    case 7:
                        str += "XXL";break; // LXX
                    case 8:
                        str += "XXXL";break; // LXXX
                    case 9:
                        str += "CX";break; // XC
                }
                break;
            case 2:
                switch(num) { // less than 1000
                    case 0:
                        return "";break;
                    case 1:
                        str += "C";break;
                    case 2:
                        str += "CC";break;
                    case 3:
                        str += "CCC";break;
                    case 4:
                        str += "DC";break; // CD
                    case 5:
                        str += "D";break;
                    case 6:
                        str += "CD";break; // DC
                    case 7:
                        str += "CCD";break; // DCC
                    case 8:
                        str += "CCCD";break; // DCCC
                    case 9:
                        str += "MC";break; // CM
                }
                break;
            case 3:
                switch(num) { // less than 10000
                    case 0:
                        return "";break;
                    case 1:
                        str += "M";break;
                    case 2:
                        str += "MM";break;
                    case 3:
                        str += "MMM";break;
                    default:
                        exit(0);
                }
                break;
        }
        
        return str;
    }
};