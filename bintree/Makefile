all : revtree posttree pretree intree bintree 

revtree : bintree.o ../../CI/objects/bintree/revtreeM.o
	gcc --std=c18 bintree.o ../../CI/objects/bintree/revtreeM.o -o revtree

posttree : bintree.o ../../CI/objects/bintree/posttreeM.o
	gcc --std=c18 bintree.o ../../CI/objects/bintree/posttreeM.o -o posttree

pretree : bintree.o ../../CI/objects/bintree/pretreeM.o
	gcc --std=c18 bintree.o ../../CI/objects/bintree/pretreeM.o -o pretree

intree : bintree.o ../../CI/objects/bintree/intreeM.o
	gcc --std=c18 bintree.o ../../CI/objects/bintree/intreeM.o -o intree

bintree : bintree.o ../../CI/objects/bintree/bintreeM.o
	gcc --std=c18 bintree.o ../../CI/objects/bintree/bintreeM.o -o bintree

bintree.o : bintree.c 
	gcc --std=c18 -c bintree.c 

