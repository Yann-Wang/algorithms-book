#include<stdio.h>
#define TO_STRING2(x) #x
#define TO_STRING(x) TO_STRING1(x)
#define TO_STRING1(x) #x
#define PARAM(x) #x
#define ADDPARAM(x) INT_##x

/*
���ȣ�C���Եĺ�������Ƕ�׵ģ���Ƕ�׺�һ���չ�����������Ĳ���һ������չ���������ٷ�������������������չ�������ǣ�ע�⣺
(1) ��������#�����ʱ���������ٱ�չ����
(2) ��������##�����ʱ������չ����������չ������Ĳ�����

PS:
##��������ڰѲ������ӵ�һ��Ԥ�������ѳ�����##����Ĳ����ϲ���һ�����ţ����ַ�������

*/
int main(){
    const char * str = TO_STRING(PARAM(ADDPARAM(1)));
    printf("%s\n",str);
    str = TO_STRING2(PARAM(ADDPARAM(1)));
    printf("%s\n",str);
    return 0;
}

/*
���ں�TO_STRING�����Ķ�����û��#��������չ������ġ�PARAM( ADDPARAM( 1 ) )����
����PARAM����#����������չ���Ľ��ΪADDPARAM( 1 )��Ȼ��������չ��������Ϊ"ADDPARAM( 1 )"
������TO_STRING2���䶨������#������ֱ��չ��������ΪPARAM( ADDPARAM( 1 ) )
*/
