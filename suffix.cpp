#include<iostream>
#include<cstdlib>
#include<stack>

using namespace std;

int operators(char ope){
	if (ope == '+' || ope == '-' || ope == '*' || ope == '/'){
		return 1 ;
	}
	else{
		return 0;
	}
}

int compare(char ope){
	switch (ope){
		case '+':
			return 1 ;break ;
		case '-':
		    return 1 ;break ;
		case '*':
		    return 2 ;break ;
		case '/':
		    return 2 ;break ;
		case '(':
		    return 0 ;break ;    
		default:
		return -1;				
	}
}

void trans(char medium[] , char suffix[] ,int &k){
	stack<char>s ;
	int j = 0 ; 
	s.push('#') ;
	for( int i = 0 ; medium[i] != '#' ; i ++ ){
		if (medium[i] >= '0' && medium[i] <= '9'){
			suffix[j] = medium[i] ;
			j ++ ;
			k ++ ;
		}
		if (medium[i] == '('){
			s.push(medium[i]);
			
		}
		if (operators(medium[i]) == 1){
			int ch1 , ch2;
			ch1 = compare(medium[i]) ;
			ch2 = compare(s.top()) ;
			while( ch1 <= ch2 ){
				suffix[j] = s.top() ;
				s.pop() ;
				ch2 = compare(s.top()) ;
				j ++ ;
				k ++ ;
				
			}
			s.push(medium[i]) ;
		}
		if (medium[i] == ')'){
			while (s.top() != '('){
				suffix[j] = s.top() ;
				s.pop() ;
				j ++ ;
				k ++ ;
			}
			s.pop() ;
		}
	}
	while(!s.empty()){
		suffix[j] = s.top() ;
		j ++ ;
		k ++ ;
		s.pop() ;
	}
}

int main(){
	char medium[50] , suffix[50] ;
	int i = 0 , k = 0 , n = 0 ;
	cout << "请输入要计算的表达式:" ;
	cin >> medium ;
	trans(medium , suffix , k) ;
	cout<< "后缀表达式为:" <<endl ;
	cout<<suffix ;
    system("pause") ;
    return 0;
}
