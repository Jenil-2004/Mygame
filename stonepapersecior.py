import random

print("Enter 1 for Stone")
print("Enter 2 for paper")
print("Enter 3 for Sessior")

p_point=0

c_point=0

while c_point!=5 or p_point!=5 :

    p_move = input("Enter your move: ")

    c_move = random.randint(1, 3)

    print("Computer got", c_move)

    if (p_move == 1 and c_move == 2) or (p_move == 2 and c_move == 3) or (p_move == 3 and c_move == 1):
            print("COMPUER WIN")
            c_point += 1
            print("COMPUTER POINT ", c_point)
            print("YOUR     POINT ", p_point)

    elif (p_move == 1 and c_move == 3) or (p_move == 2 and c_move == 1) or (p_move == 3 and c_move == 2) :
            print("YOU WON")
            p_point += 1
            print("COMPUTER POINT ", c_point)
            print("YOUR     POINT ", p_point)


    else :
            print("TIE")
            print("COMPUTER POINT ", c_point)
            print("YOUR     POINT ", p_point)



if c_point==5 :
        print("COMPUTER WIN THE GAME")

else :
        print("COMPUTER WIN THE GAME")


# print("Enter 1 for Stone")
# print("Enter 2 for paper")
# print("Enter 3 for Sessior")

# p1_move = 1
# p1_point=0

# p2_move = 10
# p2_point=0

# while p1_point!=5 or p2_point!=5 :

#         p1_move = int(input("Enter your move: "))

#         _move = random.randint(1, 3)

#         print("Computer got", c_move)

#         if (p_move == 1 and c_move == 2) or (p_move == 2 and c_move == 1) or (p_move == 3 and c_move == 2):
#             print("COMPUER WIN")
#             c_point += 1
#             print("COMPUTER POINT ", c_point)
#             print("YOUR     POINT ", p_point)

#         elif (c_move == 1 and c_move == 3) or (p_move == 2 and c_move == 3) or (p_move == 3 and c_move == 1) :
#             print("YOU WON")
#             p_point += 1
#             print("COMPUTER POINT ", c_point)
#             print("YOUR     POINT ", p_point)


#         else :
#             print("TIE")
#             print("COMPUTER POINT ", c_point)
#             print("YOUR     POINT ", p_point)



# if c_point==5 :
#     print("COMPUTER WIN THE GAME")

# else :
#     print("COMPUTER WIN THE GAME")     



