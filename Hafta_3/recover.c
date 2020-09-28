#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    // check the length of prompt
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    // open the file
    char *infile = argv[1];
    FILE *fp = fopen(infile, "r");

    // if the file cannot be opened, return error message
    if (fp == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // allocate the necessary memory
    unsigned char buffer[512];

    // filename and img to save
    char filename[10];
    FILE *img;

    // counter: will be used for naming the recovered files
    int cnt = 0;

    // read all file in 512 byte chunks
    while (fread(&buffer, 512, 1, fp))
    {
        // if beginning of a new jpg
        if (buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if this is not the first file close the last file
            if(cnt >0)
                {fclose(img);}

            // open the aptly named new file and increase the counter
            sprintf(filename, "%03i.jpg", cnt);
            img = fopen(filename, "a");
            cnt++;
        }

        // cnt cannot be 0 if a file is found
        if (cnt > 0)
            {
                // write to the current file
                fwrite(&buffer, 512, 1, img);
            }
    }

    // close any remaining files
    fclose(img);
    fclose(fp);

}
