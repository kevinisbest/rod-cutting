# rod-cutting
題目(一)：實作Rod Cutting Problem
參考資料：課本第15.1節
程式規格：
1. 輸入：其格式如下：
k
p1p2…pk
其中k為一正整數，p1,…,pk為k個分別以一格空白區隔之正整數序列，pi代表長
度為i之rod之價格。
2. 輸出：將長度為k之rod分段，所能得到之最大價格，與其切割方法。輸出格式
如下：
P
q
k=i1+i2+…+iq
其中P為最大價格、q為該鐵條分得之段數，(i1,i2,…,iq)為其分法。
輸入範例：
Input
10
1 5 8 9 10 17 17 20 24 30
Output
30
1
10=10
補充說明：
1. 參數之範圍為k<=100。
