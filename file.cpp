#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char *ROM;
int STACK[65535];
int A,B,C,D,SP,FLAG;
unsigned char OPCODE=0;
unsigned int IP=0;
int fileLen;
FILE *file;

void run(void)
{
printf("\n[!] Registers initialised to 0.");
printf("\n[!] Booting using the Boot-Rom.\n-------------------------------\n\n");
while(IP>=0 && OPCODE!=0x3c)
{
OPCODE=ROM[IP];

switch(OPCODE)
{	//MOV
case 0x11: A=STACK[SP];IP++;break;
case 0x12: B=STACK[SP];IP++;break;
case 0x13: A=B;IP++;break;
case 0x14: B=A;IP++;break;
case 0x15: STACK[SP]=A;IP++;break;
case 0x16: STACK[SP]=B;IP++;break;
case 0x17: SP=A;IP++;break;
case 0x18: SP=B;IP++;break;
case 0x19: A=SP;IP++;break;
case 0x1A: A=ROM[++IP];IP++;break;
case 0x1B: B=ROM[++IP];IP++;break;
case 0x44: A=STACK[SP+ROM[++IP]];IP++;break;
case 0x45: STACK[SP+ROM[++IP]]=A;IP++;break;
case 0x46: A=STACK[SP-ROM[++IP]];IP++;break;
case 0x47: STACK[SP-ROM[++IP]]=A;IP++;break;
case 0x4A: A = ROM[B];IP++;break;
case 0x4B: A = IP;IP++;break;
case 0x4C: A = fileLen;IP++;break;
case 0x4F: ROM[B]=A;IP++;break;
case 0x51: ROM[B]=ROM[++IP];IP++;break;
case 0x54: ROM[A] = B;IP++;break;

case 0x55: C = STACK[SP];IP++;break;
case 0x56: D=STACK[SP];IP++;break;
case 0x57: A=C;IP++;break;
case 0x58: A=D;IP++;break;
case 0x59: B=C;IP++;break;
case 0x5A: B=D;IP++;break;
case 0x5B: C=A;IP++;break;
case 0x5C: C=B;IP++;break;
case 0x5D: C=D;IP++;break;
case 0x5E: D=A;IP++;break;
case 0x5F: D=B;IP++;break;
case 0x60: D=C;IP++;break;
case 0x61: STACK[SP]=C;IP++;break;
case 0x62: STACK[SP]=D;IP++;break;
case 0x63: SP=C;IP++;break;
case 0x64: SP=D;IP++;break;
case 0x65: B=SP;IP++;break;
case 0x66: C=SP;IP++;break;
case 0x67: D=SP;IP++;break;
case 0x68: C=ROM[++IP];IP++;break;
case 0x69: D=ROM[++IP];IP++;break;
case 0x6A: B=STACK[SP+ROM[++IP]];IP++;break;
case 0x6B: C=STACK[SP+ROM[++IP]];IP++;break;
case 0x6C: D=STACK[SP+ROM[++IP]];IP++;break;
case 0x6D: STACK[SP+ROM[++IP]]=B;IP++;break;
case 0x6E: STACK[SP+ROM[++IP]]=C;IP++;break;
case 0x6F: STACK[SP+ROM[++IP]]=D;IP++;break;
case 0x70: B=STACK[SP-ROM[++IP]];IP++;break;
case 0x71: C=STACK[SP-ROM[++IP]];IP++;break;
case 0x72: D=STACK[SP-ROM[++IP]];IP++;break;
case 0x73: STACK[SP-ROM[++IP]]=B;IP++;break;
case 0x74: STACK[SP-ROM[++IP]]=C;IP++;break;
case 0x75: STACK[SP-ROM[++IP]]=D;IP++;break;
case 0x76: A = ROM[C];IP++;break;
case 0x77: A = ROM[D];IP++;break;
case 0x78: B = ROM[A];IP++;break;
case 0x79: B = ROM[C];IP++;break;
case 0x7A: B = ROM[D];IP++;break;
case 0x7B: C = ROM[A];IP++;break;
case 0x7C: C = ROM[B];IP++;break;
case 0x7D: C = ROM[D];IP++;break;
case 0x7E: D = ROM[A];IP++;break;
case 0x7F: D = ROM[B];IP++;break;
case 0x80: D = ROM[C];IP++;break;
case 0x81: ROM[A] = C;IP++;break;
case 0x82: ROM[A] = D;IP++;break;
case 0x83: ROM[B] = C;IP++;break;
case 0x84: ROM[B] = D;IP++;break;
case 0x85: ROM[C] = A;IP++;break;
case 0x86: ROM[C] = B;IP++;break;
case 0x87: ROM[C] = D;IP++;break;
case 0x88: ROM[D] = A;IP++;break;
case 0x89: ROM[D] = B;IP++;break;
case 0x8A: ROM[D] = C;IP++;break;
case 0x8B: B = IP;IP++;break;
case 0x8C: C = IP;IP++;break;
case 0x8D: D = IP;IP++;break;
case 0x8E: ROM[A]=ROM[++IP];IP++;break;
case 0x8F: ROM[C]=ROM[++IP];IP++;break;
case 0x90: ROM[D]=ROM[++IP];IP++;break;

//Addition
case 0x1C: A=A+ROM[++IP];IP++;break;
case 0x1D: A=A+B;IP++;break;
case 0x1E: B=B+ROM[++IP];IP++;break;
case 0x1F: B=B+A;IP++;break;
case 0x91: C=C+ROM[++IP];IP++;break;
case 0x92: D=D+ROM[++IP];IP++;break;
case 0x93: A=A+C;IP++;break;
case 0x94: A=A+D;IP++;break;
case 0x95: B=B+C;IP++;break;
case 0x96: B=B+D;IP++;break;
case 0x97: C=C+A;IP++;break;
case 0x98: C=C+B;IP++;break;
case 0x99: C=C+D;IP++;break;
case 0x9A: D=D+A;IP++;break;
case 0x9B: D=D+B;IP++;break;
case 0x9C: D=D+C;IP++;break;

//SUBSTRACTION

case 0x20: A=A-ROM[++IP];IP++;break;
case 0x21: A=A-B;IP++;break;
case 0x22: B=B-ROM[++IP];IP++;break;
case 0x23: B=B-A;IP++;break;
case 0x9D: C=C-ROM[++IP];IP++;break;
case 0x9E: D=D-ROM[++IP];IP++;break;
case 0x9F: A=A-C;IP++;break;
case 0xA0: A=A-D;IP++;break;
case 0xA1: B=B-C;IP++;break;
case 0xA2: B=B-D;IP++;break;
case 0xA3: C=C-A;IP++;break;
case 0xA4: C=C-B;IP++;break;
case 0xA5: C=C-D;IP++;break;
case 0xA6: D=D-A;IP++;break;
case 0xA7: D=D-B;IP++;break;
case 0xA8: D=D-C;IP++;break;


//Compare
case 0x24: FLAG=A-B;IP++;break;
case 0x25: FLAG=A-ROM[++IP];IP++;break;
case 0x26: FLAG=B-ROM[++IP];IP++;break;
case 0x48: FLAG=A-STACK[SP+(ROM[++IP])];IP++;break;
case 0x49: FLAG=B-STACK[SP+ROM[++IP]];IP++;break;
case 0xA9: FLAG=A-C;IP++;break;
case 0xAA: FLAG=A-D;IP++;break;
case 0xAB: FLAG=B-C;IP++;break;
case 0xAC: FLAG=B-D;IP++;break;
case 0xAD: FLAG=C-D;IP++;break;
case 0xAE: FLAG=C-ROM[++IP];IP++;break;
case 0xAF: FLAG=D-ROM[++IP];IP++;break;
case 0xB0: FLAG=C-STACK[SP+(ROM[++IP])];IP++;break;
case 0xB1: FLAG=D-STACK[SP+(ROM[++IP])];IP++;break;


//JMP
case 0x27: IP=A;break;
case 0x28: IP=B;break;
case 0x29: IP=IP+ROM[++IP];break;
case 0x3D: IP=IP-ROM[++IP];break;
case 0xB2: IP=C;break;
case 0xB3: IP=D;break;

//JNE
case 0x2A: if(FLAG!=0){IP=A;}else{IP++;};break;
case 0x2B: if(FLAG!=0){IP=B;}else{IP++;};break;
case 0x2C: if(FLAG!=0){IP=IP+ROM[++IP];}else{IP++;IP++;};break;
case 0xB4: if(FLAG!=0){IP=C;}else{IP++;};break;
case 0xB5: if(FLAG!=0){IP=D;}else{IP++;};break;

//JE
case 0x2D: if(FLAG==0){IP=A;}else{IP++;};break;
case 0x2E: if(FLAG==0){IP=B;}else{IP++;};break;
case 0x2F: if(FLAG==0){IP=IP+ROM[++IP];}else{IP++;IP++;};break;
case 0xB6: if(FLAG==0){IP=C;}else{IP++;};break;
case 0xB7: if(FLAG==0){IP=D;}else{IP++;};break;


//JGE
case 0x30: if(FLAG>=0){IP=A;}else{IP++;};break;
case 0x31: if(FLAG>=0){IP=B;}else{IP++;};break;
case 0x32: if(FLAG>=0){IP=IP+ROM[++IP];}else{IP++;IP++;};break;
case 0xB8: if(FLAG>=0){IP=C;}else{IP++;};break;
case 0xB9: if(FLAG>=0){IP=D;}else{IP++;};break;


//JLE
case 0x33: if(FLAG<=0){IP=A;}else{IP++;};break;
case 0x34: if(FLAG<=0){IP=B;}else{IP++;};break;
case 0x35: if(FLAG<=0){IP=IP+ROM[++IP];}else{IP++;IP++;};break;
case 0xBA: if(FLAG<=0){IP=C;}else{IP++;};break;
case 0xBB: if(FLAG<=0){IP=D;}else{IP++;};break;


//JL
case 0x4D: if(FLAG<0){IP=IP+ROM[++IP];}else{IP++;IP++;};break;
case 0xBC: if(FLAG<0){IP=A;}else{IP++;};break;
case 0xBD: if(FLAG<0){IP=B;}else{IP++;};break;
case 0xBE: if(FLAG<0){IP=C;}else{IP++;};break;
case 0xBF: if(FLAG<0){IP=D;}else{IP++;};break;

//JG
case 0xC0: if(FLAG>0){IP=A;}else{IP++;};break;
case 0xC1: if(FLAG>0){IP=B;}else{IP++;};break;
case 0xC2: if(FLAG>0){IP=C;}else{IP++;};break;
case 0xC3: if(FLAG>0){IP=D;}else{IP++;};break;
case 0xC4: if(FLAG>0){IP=IP+ROM[++IP];}else{IP++;IP++;};break;

//INC
case 0x36: ++A;IP++;break;
case 0x37: ++B;IP++;break;
case 0x38: ++SP;IP++;break;
case 0xC5: ++C;IP++;break;
case 0xC6: ++D;IP++;break;

//DEC
case 0x41: --A;IP++;break;
case 0x42: --B;IP++;break;
case 0x43: --SP;IP++;break;
case 0xC7: --C;IP++;break;
case 0xC8: --D;IP++;break;

//MISC
case 0x39: STACK[SP]=getchar();IP++;break; //scanf printf
case 0x3A: putchar(STACK[SP]);IP++;break;
case 0x3B: IP++;break;
case 0x3C: printf("\nHalt.");exit(0);
case 0x3E: usleep(ROM[++IP]);++IP;break;
case 0x3F: scanf("%d",&STACK[SP]);++IP;break;
case 0x40: printf("%d",STACK[SP]);++IP;break;
case 0x4E: printf("%X ",STACK[SP]);++IP;break;
case 0xC9: ROM=(char *)realloc(ROM,ROM[++IP]);++IP;break;

default:printf("\nInvalid Boot-rom. : %X",OPCODE);exit(0);
}
}
}

main()
{
setbuf(stdout, NULL);
printf("\n +--------------------------+");
printf("\n |  OIVM Virtual Processor  |");
printf("\n +--------------------------+");

printf("\n\n[+] Reading the Boot-Rom.");



file = fopen("bootrom.txt", "rb");
if (!file)
{
printf("\nCan't open Boot-Rom");
exit(1);
}
printf("\n[+] Read successfully.");
fseek(file, 0, SEEK_END);// fseek(pointer, offset, para 3) adds offset to para 3 and assigns it to pointer
fileLen=ftell(file);// returns location of parameter
printf("\n[+] Total Size : %lu.",fileLen);
fseek(file, 0, SEEK_SET);
ROM=(char *)malloc(fileLen+1);
if (!ROM)
{
printf("\nMemory error!");
        fclose(file);
exit(1);
}
fread(ROM, fileLen, 1, file);

fclose(file);
run();
}
