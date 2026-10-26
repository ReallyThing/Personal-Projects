import random

loop_number = 0
number = random.randint(0,10)
guess = int(input("Guess my number."+" "))
while True:
    if guess == number:
     victory_message = f"You win. The number was {number}."
     print(victory_message)
     break
    else:
     print("not it. Again."+" ")
     guess = int(input())
     loop_number = loop_number+1
     if loop_number >= 5:
         print("You seem to be struggling. Let me give you a hint:"+" ")
         distance = abs(guess-number)
         hint = f"Your guess is {distance} away from the number."
         print(hint)