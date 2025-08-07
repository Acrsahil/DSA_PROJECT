#include <stdio.h>


int main(){
    int n = 9,key = 10;
    int A[9] = {2, 4, 6, 8, 10, 12, 14, 16, 18};

    int s = 0,e = n-1;
    int ans = -1;


    int timecnt = 0;

    while(s<=e){
        timecnt++;
        int mid = (s+e)/2;

        if(A[mid] == key){
            ans = mid;
            break;
        }else if(key<A[mid]){
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    printf("We found the element %d at index %d in %d iterations.\n",key,ans,timecnt);
}
