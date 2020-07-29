#include <cstdio>

int main()
{
	FILE *fin, *fout;
	fin = fopen("data.in", "rb");
	fout = fopen("data.out", "wb");
	int x;
	while (fscanf(fin, "%d", &x))
	{
		fprintf(fout, "%d", x);
	}
	fclose(fin);
	fclose(fout);

	fin = stdin;
	fout = stdout;

	freopen("data.in", "rb", stdin);
	freopen("data.out", "wb", stdout);
}
