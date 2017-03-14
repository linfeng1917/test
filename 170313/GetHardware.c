#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
void get_hardware_name(char *hardware, unsigned int *revision)
{
    const char *cpuinfo = "/proc/cpuinfo";
    char *data = NULL;
    size_t len = 0, limit = 1024;
    int fd, n;
    char *x, *hw, *rev;

    /* Hardware string was provided on kernel command line */
    if (hardware[0])
        return;

    fd = open(cpuinfo,O_RDONLY);
    if (fd < 0) return;

    for (;0;) {
        //x = realloc(data, limit);
		x = malloc(limit);
        if (!x) {
            printf("Failed to allocate memory to read %s\n", cpuinfo);
            goto done;
        }
        data = x;

        n = read(fd, data + len, limit - len);
        if (n < 0) {
            printf("Failed reading %s\n", cpuinfo);
            goto done;
        }
        len += n;

        if (len < limit)
            break;

        /* We filled the buffer, so increase size and loop to read more */
        limit *= 2;
    }
	printf("data is %s\n",data);
    data[len] = 0;
    hw = strstr(data, "\nHardware");
    rev = strstr(data, "\nRevision");

    if (hw) {
        x = strstr(hw, ": ");
        if (x) {
            x += 2;
            n = 0;
            while (*x && *x != '\n') {
             //   if (!isspace(*x))
                    //hardware[n++] = tolower(*x);
                hardware[n++] = *x;
                x++;
                if (n == 31) break;
            }
            hardware[n] = 0;
        }
    }
printf("hardware in %s, is %s\n",__func__,hardware);
/*    if (rev) {
        x = strstr(rev, ": ");
        if (x) {
            *revision = strtoul(x + 2, 0, 16);
        }
    }*/

done:
    close(fd);
    free(data);
}

int main(int argc, const char *argv[])
{
	char h[32] ={};
	int r[32] = {0};
	get_hardware_name(h,r);
	printf("hardware is %s\n",h);
	return 0;
}
