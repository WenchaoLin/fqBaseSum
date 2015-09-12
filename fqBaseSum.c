/*************************************************************************
	> File Name: base_sum.c
	> Author: linwenchao
	> Mail: linwenchao@yeah.net
	> Created Time: Fri 11 Sep 2015 04:32:32 PM CST
 ************************************************************************/

#include <stdio.h>
#include <zlib.h>  
#include <stdio.h>  
#include "kseq.h"  


// STEP 1: declare the type of file handler and the read() function  
KSEQ_INIT(gzFile, gzread)  

int printUsage(char *exe){
    fprintf(stderr,"Usage: %s <in.fq> | <in.fq.gz>\n\n\tCount number of bases and reads in a fastq file.\n\t(gziped file supported)\n\n\tby:linwenchao@TBC\n", exe);
    return 1;
}
  
int main(int argc, char *argv[])  
{  
    gzFile fp;  
    kseq_t *seq;  
    int l;  
    char *fqName;
    if (argc == 1){  
//        fprintf(stderr, "Usage: %s <in.fq>\n", argv[0]);  
        printUsage(argv[0]);
    	exit(1);
    }
    long int n = 0, slen = 0;
    fp = gzopen(argv[1], "r"); // STEP 2: open the file handler  
    seq = kseq_init(fp); // STEP 3: initialize seq  
    while ((l = kseq_read(seq)) >= 0) { // STEP 4: read sequence  
        ++n, slen += seq->seq.l;
    }  
    
    printf("%s\tNum reads:%ld\tNum Bases: %ld\n",argv[1], n, slen); 
    kseq_destroy(seq); // STEP 5: destroy seq  
    gzclose(fp); // STEP 6: close the file handler  
    return 0;  
}  

