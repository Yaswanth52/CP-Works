Time Complexity: O(m+n)

void buildLPS(string &pat,lld lps[]){
    lld m=sz(pat);
    lps[0]=0;
    lld len=0,i=1;
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i++]=len;
        }
        else{
            if(len){
                len=lps[len-1];
            }
            else
            {
                lps[i++]=0;
            }
        }
    }
}
lld kmp(string &txt,string &pat){
    lld n=sz(txt),m=sz(pat);
    lld lps[m];
    buildLPS(pat,lps);
    lld matches=0;
    lld i=0,j=0;
    while(i<n){
        if(txt[i]==pat[j]){
            i++,j++;
        }
        else{
            if(j)
                j=lps[j-1];
            else
                i++;
        }
        if(j==m){
            matches++;
            j=lps[j-1];
        }
    }
}
  
