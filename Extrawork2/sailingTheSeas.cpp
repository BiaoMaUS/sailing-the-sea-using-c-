#include<iostream>
using namespace std;
const int row=10, column=10;
int newr,newc,oldr,oldc;
void initMap(char arr[row][column]){
  for(int r=0;r<row;r++){
    for(int c=0;c<column;c++){
      if(c<=r){
        arr[r][c]='~';
        arr[5][5]='s';
        cout<<arr[r][c]<<" ";
      }
      else{
        arr[r][c]='.';
        cout<<arr[r][c]<<" ";
      }

    }
    cout<<endl;
  }
}
//displayMap
void displayMap(char arr[row][column]){
  for(int r=0;r<row;r++){
    cout<<r<<" ";
    for(int c=0;c<column;c++){

      if(c<=r){
        arr[r][c]='~';
        arr[5][5]='s';
        cout<<arr[r][c]<<" ";
      }
      else{
        arr[r][c]='.';
        cout<<arr[r][c]<<" ";
      }

    }
    cout<<endl;
  }
  cout<<" "<<" ";
  for(int h=0; h<10;h++){
    cout<<h<<" ";
  }
  cout<<endl;
}
//getSmallCase;
 char validate(char a){
  char b;

  int i= a;
  if(i>90){
    return a;
  }
  else{
  b=i+32;
  return b;

}
}
// moveShip
void moveShip(char arr[row][column]){

  //if(arr[newr][newc]=='~'){
  for(int r=0;r<row;r++){
    cout<<r<<" ";
    for(int c=0;c<column;c++){

      if(c<=r){
        arr[r][c]='~';
        arr[newr][newc]='s';
        cout<<arr[r][c]<<" ";
      }
      else{
        arr[r][c]='.';
        cout<<arr[r][c]<<" ";
      }

    }
    cout<<endl;
  }
  cout<<" "<<" ";
  for(int h=0; h<10;h++){
    cout<<h<<" ";
  }
  cout<<endl;
//}

//else{
  //if(arr[newr][newc]=='.'){
  //  cout<<"crash"<<endl;
  //}
  //else{
  //  cout<<"lost"<<endl;
  //}
//}
}
//menu function
void menu(char arr[row][column]){
  displayMap(arr);
  newr=5;
   newc=5;
   oldr=5;
   oldc=5;
  do{
    cout<<endl;
    cout<<"n)orth"<<endl;
    cout<<"s)outh"<<endl;
    cout<<"e)ast"<<endl;
    cout<<"w)ast"<<endl;
    cout<<endl;
    cout<<"which way, captain? ";
    char select;
    cin>>select;

    select=validate(select);
    switch(select){
      case 'n':
      oldc=oldc;
      oldr=--oldr;
if(arr[oldr][oldc]=='~'){
              newc=newc;
              newr=--newr;
              moveShip(arr);
        }     else{
          break;
        }
         break;

      case 's':

      oldc=oldc;
      oldr=++oldr;
if(arr[oldr][oldc]=='~'){
              newc=newc;
              newr=++newr;
              moveShip(arr);
        }     else{
          break;
        }
         break;

      case 'e':

      oldc=++oldc;
      oldr=oldr;
if(arr[oldr][oldc]=='~'){
              newc=++newc;
              newr=newr;
              moveShip(arr);
        }     else{
          break;
        }
         break;

      case 'w':

      oldc=--oldc;
      oldr=oldr;

if(arr[oldr][oldc]=='~'){
              newc=--newc;
              newr=newr;
              moveShip(arr);
        }     else{
          break;
        }
         break;

      default:
      cout<<"pick a direction!"<<endl;
    }

  }while(arr[oldr][oldc]=='s');
  if(oldr<0||oldc<0){
    cout<<endl;
    cout<<"ARGGGH!!!...you have been lost at sea!!!"<<endl;
  }else{
  if(arr[oldr][oldc]=='.'){
    cout<<endl;
    cout<<"crash!!! You boat begins to sink!"<<endl;
  }
  else{
    cout<<endl;
    cout<<"ARGGGH!!!...you have been lost at sea!!!"<<endl;
  }
}
}
int main(){

  char arr[row][column];
  cout<<"Sailing the seas"<<endl;
  cout<<"----------------"<<endl;
  menu(arr);


  return 0;
}
