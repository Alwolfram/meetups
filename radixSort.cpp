#include<bits/stdc++.h>
using namespace std;
//template<class R>
int range = 8;
class radixSort
{
public:
    int getMax(int *arr, int n)
    {
        int mx = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > mx)
                mx = arr[i];
        return mx;
    }
    void countsort(int *arr,int n,int place)
    {
        int i,freq[range]={0};
        int output[n];

        for(i=0;i<n;i++)
                freq[(arr[i]/place)%range]++;
        for(i=1;i<range;i++)
                freq[i]+=freq[i-1];
        for(i=n-1;i>=0;i--)
        {
                output[freq[(arr[i]/place)%range]-1]=arr[i];
                freq[(arr[i]/place)%range]--;
        }
        for(i=0;i<n;i++)
                arr[i]=output[i];
    }
    void Sort(int *arr,int n)
    {
        int mul=1;
        int maxx = getMax(arr,n);
        while(maxx)
        {
                countsort(arr,n,mul);
                mul*=10;
                maxx/=10;
        }
    }

};

int main()
{
    radixSort r;
    int A[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    r.Sort(A,8);
    for(auto it: A)
        cout<<it<<" ";

}
