# Program called 'Coffee or Tea, I see' that asks for user input on a drink,
# And gives change and a report back.

print("")
print("Hello, welcome to my program 'Coffee or Tea, I see'")
print("")
print("")

# -----------------------------------------------------Input Ordering Section-------------------------------------------------- :

# Obtain the customer's name.
CustomerName = input("Please enter your first name. ")
print("")
NameCheck = "f"
# Error Check - Checks through the length of the CustomerName for any spaces and if found gives an error message and exits.
for initial in range(0, len(CustomerName)):
        if CustomerName[initial] == " ":
            print("Invalid Answer; (",CustomerName,") is not an appropriate name. There are no spaces in first names.")
            exit()
        initial += 1
# Error Check - Checks through the CustomerName for any numbers and if found gives an error message and exits.
while NameCheck == "f":
    if CustomerName.isalpha():
      NameCheck = "t"
    else:
      print("Invalid Answer; (",CustomerName,") is not an appropriate name. Names cannot have numbers.")
      exit()

# Find out whether the customer wants coffee or tea.
BeverageType = str(input("What type of beverage would you like: Coffee or Tea? ")).lower()
print("")
while (BeverageType != "coffee") and (BeverageType != "c") and (BeverageType != "tea")and (BeverageType != "t"):
    print("")
    print("Invalid Answer; (",BeverageType,") is not a beverage offered on the menu.")
    exit()
# Setting the BeverageType correct short form inputs to its full name for the final print message and other variable checks.
if BeverageType == "c":
    BeverageType = "coffee"
if BeverageType == "t":
    BeverageType = "tea"

# Find out whether the customer wants small, medium or large.
DrinkSize = str(input("Please enter your beverage size: Small, Medium, or Large. ")).lower()
while (DrinkSize != "small") and (DrinkSize != "s") and (DrinkSize != "medium") and (DrinkSize != "m") and (DrinkSize != "large") and (DrinkSize != "l"):
    print("")
    print("Invalid Answer; (",DrinkSize,") is not a size offered on the menu.")
    exit()
# Setting the DrinkSize correct short form inputs to its full name for the final print message and other variable checks.
if DrinkSize == "s":
    DrinkSize = "small"
if DrinkSize == "m":
    DrinkSize = "medium"
if DrinkSize == "l":
    DrinkSize = "large"
print("")

# Get the type of flavour shot desired.
print("Is there any flavour shots you would like?")
print("")
CoffeeOption = "coffee"
TeaOption = "tea"
FlavourShot = "Empty"
FlavourInput = "f"
# While the FlavourShot value (originally "Empty") does not equal any of the correct menu options it will run this while loop.
while (FlavourShot != "none") and (FlavourShot != "") and (FlavourShot != "vanilla") and (FlavourShot != "v") and (FlavourShot != "chocolate") and (FlavourShot != "c") and (FlavourShot != "maple") and (FlavourShot != "m") and (FlavourShot != "lemon") and (FlavourShot != "l") and (FlavourShot != "mint"):
    # Error Check - If the value of the FlavourInput is not "f" (Which it starts as) then the error message appears and the code ends.
    if FlavourInput != "f":
        print("")
        print("Invalid Answer; (",FlavourShot,") is not a flavour offered on the menu.")
        exit()
    if BeverageType == CoffeeOption:
        FlavourShot = input("Your choices are: None, Vanilla, Chocolate, or Maple. ").lower()
        print("")
        # Sets the FlavourInput to true, so if the code ran through the loop again (due to not entering a correct menu option)
        # Then the code would go to the error check and give an error message. Although if given a valid option it will not even
        # Go back through the while loop.
        FlavourInput = "t"
        # Setting the FlavourShot correct short form inputs to its full name for the final print message and other variable checks.
        if FlavourShot == "":
            FlavourShot = "none"
        if FlavourShot == "v":
            FlavourShot = "vanilla"
        if FlavourShot == "c":
            FlavourShot = "chocolate"
        if FlavourShot == "m":
            FlavourShot = "maple"
        # Error Check - Makes sure that a flavour shot for coffee is entered, not a tea flavour.
        if FlavourShot == "mint" or FlavourShot == "lemon":
            print("")
            print("Invalid Answer; (",FlavourShot,") is a tea flavour shot, not a coffee flavour shot.")
            exit()
    elif BeverageType == TeaOption:
        FlavourShot = input("Your choices are: None, Lemon, or Mint ").lower()
        print("")
        # Sets the FlavourInput to true, so if the code ran through the loop again (due to not entering a correct menu option)
        # Then the code would go to the error check and give an error message. Although if given a valid option it will not even
        # Go back through the while loop.
        FlavourInput = "t"
        # Setting the FlavourShot correct short form inputs to its full name for the final print message and other variable checks.
        if FlavourShot == "":
            FlavourShot = "none"
        if FlavourShot == "m":
            FlavourShot = "mint"
        if FlavourShot == "l":
            FlavourShot = "lemon"
        # Error Check - Makes sure that a flavour shot for tea is entered, not a coffee flavour.
        if FlavourShot == "vanilla" or FlavourShot == "chocolate" or FlavourShot == "maple":
             print("")
             print("Invalid Answer; (",FlavourShot,") is a coffee flavour shot, not a tea flavour shot.")
             exit()

# Making it so no flavour shot says no flavouring in the end message instead of none flavouring.
if FlavourShot == "none":
             FlavourShot = "no"

# -----------------------------------------------------Cost Calculation Section--------------------------------------------------:

# Cost Calculation for Drink Size.
SizeCost = 0
if DrinkSize == "small":
    SizeCost = 1.50
elif DrinkSize == "medium":
    SizeCost = 2.50
elif DrinkSize == "large":
    SizeCost = 3.25

# Cost Calculation for Flavour choice.
FlavourCost = 0
if FlavourShot == "vanilla":
    FlavourCost = 0.25
elif FlavourShot == "chocolate":
    FlavourCost = 0.75
elif FlavourShot == "maple":
    FlavourCost = 0.50
elif FlavourShot == "lemon":
    FlavourCost = 0.25
elif FlavourShot == "mint":
    FlavourCost = 0.50

# Final Cost Calculation.
Tax = (SizeCost + FlavourCost)*0.11
TotalCost = Tax + SizeCost + FlavourCost
CustomerName = CustomerName.title()

# Final print message.
print("")
print("")
print("")
print("")
print("For",CustomerName,", a",DrinkSize, BeverageType, ",", FlavourShot,"flavouring, cost: $%.2f." % round(TotalCost,2))
