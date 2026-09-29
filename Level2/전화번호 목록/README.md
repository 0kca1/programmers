phone_book을 오름차순으로 정렬하면, 문자열이니까 사전처럼 정렬  
그럼 i번째와 i + 1번째만 비교하면 true인지 false인지 나옴  

ex) "12" "3456" "1234" >> "12" "1234" "3456"  // "12" 가 "1234"의 접두어 false  
    "123" "789" "456" >> "123" "456" "789" //  true  

i번쨰와 i + 1번째만 비교하면 되기 떄문에,  string a, b에 각각 저장  

여기서 phone_book의 사이즈가 5라고 가정하면, i는 0부터 4까지 phone_book[4]가 끝.
for(i = 0; i < phone_book; i++)  >> for(i = 0; i + 1 < phone_book; i++) 
{
    string a = phone_book[i];
    string b = phone_book[i + 1];   << 하지만 여기서 phone_book[5]가 되면서 error.
}  
그렇기 때문에 for문 범위를 잘 생각할 것.
