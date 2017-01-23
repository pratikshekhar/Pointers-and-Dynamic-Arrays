:PHONY: compile

compile: question1.c question2.c question3.c question4.c question5.c 
	gcc -o question1 question1.c
	gcc -o question2 question2.c
	gcc -o question3 question3.c
	gcc -o question4 question4.c
	gcc -o question5 question5.c

ques1 : question1
	./question1

ques2 : question2
	./question2

ques3 : question3
	./question3

ques4 : question4
	./question4

ques5 : question5
	./question5

ques5: question5
	./question5
