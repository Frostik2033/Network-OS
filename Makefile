all: Lec2_3_1 Lec2_3_2 Lec2_3_3 Lec4_1 Lec4_2 Lec4_3

Lec2_3_1: Lec2_3/Program1.c
	gcc -o Lec2_3_1.out Lec2_3/Program1.c

Lec2_Lec3_2: Lec2_3/Program2.c
	gcc -o Lec2_3_2.out Lec2_3/Program2.c

Lec2_Lec3_3: Lec2_Lec3/Program3.c
	gcc -o Lec2_3_3.out Lec2_3/Program3.c
	
Lec4_1: Lec4/Program4.c
	gcc -o Lec4_1.out Lec4/Program4.c

Lec4_2: Lec4/Program5.c
	gcc -o Lec4_2.out Lec4/Program5.c

Lec4_3: Lec4/Program6.c
	gcc -o Lec4_3.out Lec4/Program6.c
