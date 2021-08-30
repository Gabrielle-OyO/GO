#include<stdio.h>
typedef float Stack;
typedef float S;
int main(){
    void BracketMatch(char*str){
        Stack<char>S;
        int i;
        char ch;//栈可以是顺序或链式的，都一样引用
        for(i=0;str[i]!='\0';i++){
            switch(str[i]){
                case'(':case'[':case'{':
                    S.Push(str[i]);
                    break;
                case')':case']':case'}':
                    if(S.IsEmpty()){
                        cout<<"右括号多余!";return;
                    }else{
                        ch=S.GetTop();
                        if(Match(ch,str[i]))
                            ch=S.Pop();
                        else{
                            cout<<"括号不匹配!";
                            return;
                        }
                    }/*else*/
            }/*switch*/
        }/*for*/
        if(S.IsEmpty())
            cout<<"括号匹配!";
        else cout<<"左括号多余";
    }

}

