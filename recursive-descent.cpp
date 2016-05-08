/*
 递归下降分析程序 
 author ZSY
 文法： S->(A)|aAb   A->eA'|dSA'   A'->dA'|null 

*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int S();  //子程序P(S) 
int A();  //子程序 P(A) 
int _A();  //子程序 P(A')
int subs;  //语句的数组下标 
char str[20]; //用来存输入的字符串 

main(){
	int len;  //用来存输入字符串的长度 
    int m;  //要测试的语句的次数 
    printf("当前的文法为:\n\t S->(A)|aAb \n\t A->eA'|dSA' \n\t A'->dA'|null\n");
    printf("你想测试几条语句，请输入次数：");  
    scanf("%d",&m);  
    while(m--)  
    {  
        printf("请输入语句（少于20个字符）：");  
        scanf("%s",str);  
        len = strlen(str);  
        str[len]='#';  
        str[len+1]='\0';  
        S();
        printf("这是一条正确的语句，符合当前的文法\n");  
        strcpy(str,"");  
        subs = 0;  
    } 
} 

int S(){
	if(str[subs] == '('){
		subs++;
		A();
		if(str[subs] == ')'){
			subs++;
		}else{
			printf("\n此语句不符合当前文法!\n");  
            exit(0);
		}
	}else if(str[subs] != 'a'){
		printf("\n此语句不符合当前文法!\n");  
  		exit(0);
	}else{
		subs++;
		A();
		if(str[subs] == 'b'){
			subs++;
		}else{
			printf("\n此语句不符合当前文法!\n");
            exit(0);
		}
	}
}

int A(){
	if(str[subs] == 'e'){
		subs++;
		_A();
	}else if(str[subs] != 'd'){
		printf("\n此语句不符合当前文法\n");
  		exit(0);
	}else{
		S();
	} 
}

int _A(){
	if(str[subs] == 'd'){
		subs++;
		_A();
	}else if(str[subs] == 'b'){
 		return 0;
	}else if(str[subs] == ')'){
 		return 0;
	}else{
		printf("\n此语句不符合当前文法\n");
  		exit(0);
	}
}