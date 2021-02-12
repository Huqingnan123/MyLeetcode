class Solution {
public:
    // ����ת����԰�ֿ��Եõ�һ��������СԪ�ص�����ת���飬�Լ���һ���ǵݼ���������顣
    // ���ڿ������ظ����֣���������mid == rightֵ�������޷�ȷ��ѡ�ĸ����䣬�������ں�right--
    int minArray(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            //mid��������СԪ�أ���right == mid
            if (numbers[mid] < numbers[right])
                right = mid;
            //mid����������СԪ�أ���left == mid+1
            else if (numbers[mid] > numbers[right]) 
                left = mid + 1;
            //��ϱ�������С����
            else if (numbers[mid] == numbers[right])
                right--;
        }
        return numbers[left];
    }
};