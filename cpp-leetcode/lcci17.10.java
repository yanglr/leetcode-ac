int findMajorityElement(int[] array) {
int candidate = getCandidate(array);
return validate(array, candidate) ? candidate : -1;
}
int getCandidate(int[] array) {
int majority = 0;
int count = 0;
for (int n : array) {
 if (count == 0) { // 前面的集合中没有主要元素
 majority = n;
 }
 if (n == majority) {
 count++;
 } else {
 count--;
 }
 }
 return majority;
 }

 boolean validate(int[] array, int majority) {
 int count = 0;
 for (int n : array) {
 if (n == majority) {
 count++;
 }
 }

 return count > array.length / 2;
 }