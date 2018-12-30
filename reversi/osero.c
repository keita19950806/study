#include<stdio.h>

#define NUM	"0 1 2 3 4 5 6 7"

int field[8][8]={0}; //盤
int flag=0; //ひっくり返すためのフラグ

//表示用関数
void show(){
  int i,j;
  printf("\n  %s\n",NUM);
  for(i=0;i<8;i++){
    printf("%d",i);
    for(j=0;j<8;j++){
      switch(field[i][j]){
      case 0:
	printf("ー");
	break;
      case 1:
	printf("●");
	break;
      case 2:
	printf("○");
	break;
      default:
	printf("NN");
      }
    }
    printf("\n");
  }
}

//石の状態を調べ、ひっくり返す関数
int check(int ro,int co,int i,int j,int turn){ 
  if(field[ro][co]==turn){ //自分の石と同じ色
    flag=1;
    return turn;
  }else if(field[ro][co]==0){ //空白
    return (turn==1 ? 2 : 1);
  }else{ //相手の石と同じ色
    field[ro][co]=check(ro+i,ro+j,i,j,turn); 
    if(flag=1)
      return turn;
    else
      return (turn==1 ? 2 : 1);
  }
  return -1;
}

//置いた石の周囲8マスを探索する関数
int search(int ro,int co,int turn){
  int i,j;
  int success=0;
  
  //(ro,co)の周囲8マスを調べる
    for(i=-1;i<=1;i++){
      for(j=-1;j<=1;j++){
	if(!(i==0 && j==0)   &&
	   //ro+i>=0 && ro+i<8 &&
	   //co+j>=0 && co+j<8 &&
	   ro+2*i>=0 && ro+2*i<8 &&
	   co+2*j>=0 && ro+2*i<8 &&
	   field[ro+i][co+j]!=0 && field[ro+i][co+j]!=turn)
	{
	  field[ro+i][co+j]=check(ro+2*i,co+2*j,i,j,turn);
	  if(flag==1 && success==0)
	    success=1;
	}
      }
    }
    return success;
}  

int main(){
  int turn=1; //1:○,2:●
  int ro,co;//行(row),列(column)
  int success; //探索に失敗したかどうかを判定するフラグ
  
  //初期化
  field[3][3]=1;
  field[3][4]=2;
  field[4][3]=2;
  field[4][4]=1;
  //-------
  
  while(1){
    show();
    do{
      printf("turn %s:",(turn==1 ? "●":"○"));
      scanf("%d %d",&ro,&co);
    }while(field[ro][co]!=0);
    field[ro][co]=turn;
    success=search(ro,co,turn);
    if(success==0){ //探索したが、ひっくり返せる場所が無かった場合
      printf("cannot put.\n");
      field[ro][co]=0;
      continue;
    }
    success=0;
    turn=(turn==1 ? 2 : 1);

 }
  return 0;
}
