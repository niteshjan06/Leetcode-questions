class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int maxi=max(a.length(),b.length());
        int carry=0;

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        for(int i=0;i<maxi;i++){
            if(i<a.length() && i<b.length()){
                int total=(a[i]-'0'+b[i]-'0')+carry;

                if(total<=1){
                    ans+=char(total+'0');
                    carry=0;
                }else if(total == 2){
                    ans+='0';
                    carry=1;
                }else{
                    ans+='1';
                    carry=1;
                }
            }else{
                if(i<a.length()){
                    int total=(a[i]-'0')+carry;

                    if(total<=1){
                        carry=0;
                        ans+=char(total+'0');
                    }else{
                        ans+='0';
                        carry=1;
                    }
                }else{
                    int total=(b[i]-'0')+carry;

                    if(total<=1){
                        carry=0;
                        ans+=char(total+'0');
                    }else{
                        ans+='0';
                        carry=1;
                    }
                }
            }
        }

        if(carry){
            ans+=char(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
