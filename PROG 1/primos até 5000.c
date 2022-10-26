#include <stdio.h>
int main ()
{
int primo=5, divisao=1, qnt=0;

for (primo = 5; primo <= 5000; primo++)
{
qnt = 0;
for (divisao =2; divisao < primo; divisao++)
{
if (primo%divisao == 0)
{
qnt++;
}
}
if (qnt == 0)
printf("%d\n", primo);
}


}
