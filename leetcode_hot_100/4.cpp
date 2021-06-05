class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        int pos = (sum)/2+1;
        int a = 0, b= 0;
        int number1 = 0, number2 = 0;
        while(a + b < pos)
        {
            number1 = number2;
            if ( a == nums1.size() )
            {
                number2 = nums2[b];
                b++;
            }
            else if ( b == nums2.size() || nums1[a] < nums2[b])
            {
                number2 = nums1[a];
                a++;
            }
            else
            {
                number2 = nums2[b];
                b++;
            }
            //cout << a <<' '<< b << ' '<< number1<< ' '<<number2<<endl;
        }
        if (sum % 2 == 1)
            return number2;
        else
            return (number1 + number2)* 1.0 / 2;
    }
};