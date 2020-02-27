/* Following program is a C implementation of Rabin Karp 
Algorithm given in the CLRS book */
#include<stdio.h> 
#include<string.h>
#include<time.h> 

// d is the number of characters in the input alphabet 
#define d 256 

/* pat -> pattern 
	txt -> text 
	q -> A prime number 
*/
void search(char pat[], char txt[], int q) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 
	int i, j; 
	int p = 0; // hash value for pattern 
	int t = 0; // hash value for txt 
	int h = 1; 

	// The value of h would be "pow(d, M-1)%q" 
	for (i = 0; i < M-1; i++) 
		h = (h*d)%q; 

	// Calculate the hash value of pattern and first 
	// window of text 
	for (i = 0; i < M; i++) 
	{ 
		p = (d*p + pat[i])%q; 
		t = (d*t + txt[i])%q; 
	} 

	// Slide the pattern over text one by one 
	for (i = 0; i <= N - M; i++) 
	{ 

		// Check the hash values of current window of text 
		// and pattern. If the hash values match then only 
		// check for characters on by one 
		if ( p == t ) 
		{ 
			/* Check for characters one by one */
			for (j = 0; j < M; j++) 
			{ 
				if (txt[i+j] != pat[j]) 
					break; 
			} 

			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
			if (j == M) 
				printf("Pattern found at index %d \n", i); 
		} 

		// Calculate hash value for next window of text: Remove 
		// leading digit, add trailing digit 
		if ( i < N-M ) 
		{ 
			t = (d*(t - txt[i]*h) + txt[i+M])%q; 

			// We might get negative value of t, converting it 
			// to positive 
			if (t < 0) 
			t = (t + q); 
		} 
	} 
} 

/* Driver program to test above function */
int main() 
{ 
	char txt[] = "The company has established itself over many decades as one of the world’s leading specialists for industrial drying and mixing of food and food additives. The Döhler Group has been the majority shareholder with 90 per cent of the shares in MOLDA AG since May 2015. As a result of the recently completed acquisition of the remaining 10 per cent of the free-floating shares, the former MOLDA AG has now become a 100% Döhler Group subsidiary.With the integration of the dry ingredient specialist MOLDA into the globally active corporation, Döhler brings together substantial expertise for the food and beverage industry under one roof: customers will receive dry and liquid ingredient solutions from a single source in future. By expanding its portfolio of natural dry ingredients and dry systems, Döhler is also strengthening its competences for natural ingredients and ingredient systems – in particular for the food industry. The premium portfolio ranges from freeze-dried fruits, fruit granulates, fruit pieces and fruit powders to innovative powder solutions for beverages, individual bakery and pastry mixes up to a wide variety of milk and fat-based ingredients and high-quality speciality products such as red wine and honey powder. The centre of expertise for drying technologies is being further expanded under the leadership of the two Managing Directors, Ulrich Kühle and Michael Ulrich. “Products from Molda – from now on Döhler Dahlenburg GmbH – represent 100 naturalness, sustainability and outstanding multi-sensory properties. With this high quality standard, the portfolio adapts seamlessly to Döhler’s product world. Döhler Dahlenburg is an essential part of the Döhler portfolio when it comes to providing comprehensive ingredient solutions to the food industry,” says Ulrich Kühle. Michael Ulrich adds, “We will invest heavily in capacity expansion measures and new technologies at the Dahlenburg site over the next few years."; 
	char pat[] = "being further expanded"; 
	clock_t startt,endt; 
	double totalt;
	int q = 101; // A prime number 
	startt=clock(); 
	search(pat, txt, q);
	endt=clock();
	totalt=(float)(endt-startt)/CLOCKS_PER_SEC;
	printf("%f\n\t",totalt); 
	return 0; 
} 

