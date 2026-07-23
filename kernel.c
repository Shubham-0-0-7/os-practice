void main(){
    char* video_memory = (char*)0xb8000;
    char* msg = "hellow, from C kernel";
    int i=0;
    while(msg[i]!='\0'){
        video_memory[2*i]=msg[i];
        video_memory[2*i+1]=0x0f;
        i++;
    }

}
