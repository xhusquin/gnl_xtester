# gnl_xtester
This is just my personnal Makefile for my get_next_line project in C.
This is not really a tester (I´ḿ still not good enough with code for that....),
but more a way to have a visual comparaison with the original file.

Basically, you will first see the result of the cat -En command
followed by the result of the get_next_line fonction.

Each lines should start with his number in green after a red $
(Exept for the first one), the text should finish with (null).

Put this in your folder and type make, 
then you can launch the gnl_xtester.out followed by the name of a provided text file.
BUFFER_SIZE is supposed to be managed in your own header file.

for the bonus, type make bonus.
launch just gnl_xtester.out, you can not change the text.

Hope it help ;)
