from country import Country

class CountryCatalogue:
    def __init__(self, continent_file, data_file):
        data_file = open(data_file, 'r')
        continent_file = open(continent_file, 'r')
         # cDictionary is a dictionary where the key is the country name and value is the continent.
        self._cDictionary = {}
        # CountryCat is a collection of countries from the class Country.
        self._countryCat = {}

        # Ignores header.
        next(continent_file)
        # Fills the cDictionary.
        for line in continent_file:
            line_parts = line.strip().split(",")
            self._cDictionary[line_parts[0]] = line_parts[1]
        #print(self._cDictionary["China"])

        # Ignores header.
        next(data_file)
        # Fills the catalogue:
        # By separating the lines based on "|", and then further by ","
        # Then by converting components into integer and float correspondingly.
        for line in data_file:
            line_parts = line.strip().split("|")
            line_parts[1] = int((line_parts[1].replace(",", "")))
            line_parts[2] = float((line_parts[2].replace(",", "")))
            # Makes it an object of the Class Country
            self._countryCat[line_parts[0]] = (Country(line_parts[0], line_parts[1], line_parts[2], self._cDictionary[line_parts[0]]))

    # Allows the user to look up information on the countries, taking in a country name as input.
    def findCountry(self):
        country_input = str(input("What country would you like to look up? "))
        if country_input in self._countryCat:
            return self._countryCat[country_input]
        else:
            return

    # Allows the user to change the country population of a country in the catalogue (if in catalogue).
    def setPopulationOfCountry(self):
       country_input = str(input("What country would you like to change the population of? "))
       newPop_input = str(input("Please enter a new population value: "))
       if country_input in self._countryCat:
           self._countryCat[country_input]._c_pop = newPop_input
           return "True"
       else:
           return "False"

    # Allows the user to change the country area of a country in the catalogue (if in catalogue).
    def setAreaOfCountry(self):
       country_input = str(input("What country would you like to change the area of? "))
       newArea_input = str(input("Please enter a new area value: "))
       if country_input in self._countryCat:
           self._countryCat[country_input]._c_area = newArea_input
           return "True"
       else:
           return "False"

    # Allows a user to add a country and all it's components.
    def addCountry(self):
       newName_input = str(input("Please enter the name of your new country: "))
       newPop_input = str(input("Please enter a population value for the new country: "))
       newArea_input = str(input("Please enter an area value for the new country: "))
       newCon_input = str(input("Please enter a continent value for the new country: "))
       if newName_input in self._countryCat:
           return "False"
       self._countryCat[newName_input] = (Country(newName_input, newPop_input, newArea_input, newCon_input))
       self._cDictionary[newName_input] = newCon_input
       return "True"

    # Allows the user to remove a country.
    def deleteCountry(self):
        country_input = str(input("What country would you like to remove? "))
        if country_input in self._countryCat:
            self._countryCat.pop(country_input, None)

    # Prints the default string representation of the countryCat catalogue.
    def printCountryCatalogue(self):
        print(self._countryCat)

    # Allows the user to input a continent, and returns a list of countries.
    def getCountriesByContinent(self):
        continent_input = str(input("Please input the continent that you would like to see the countries of: "))
        countriesByContinent = []
        for key in self._cDictionary:
            if self._cDictionary[key] == continent_input:
                countriesByContinent.append(key)
        return countriesByContinent

    # Allows the user to input a population, and returns a list of pairs(tuples) as country/population.
    # The list outputted will be in descending order from largest to smallest population.
    def getCountriesByPopulation(self):
        continent_input = str(input("Please input the continent that you would like to see the countries of (in order of descending population): "))
        # Stores a list of all countries in a selected continent.
        countriesByContinent = []
        # Stores a list of the country populations in order of largest to smallest.
        populationList = []
        # Stores a list of the country names in order of largest to smallest population (done using populationList).
        nameList = []
        # First for loop is used in the previous method, finding all countries in a continent.
        for key in self._cDictionary:
            if self._cDictionary[key] == continent_input:
                countriesByContinent.append(key)
        # Second for loops gets all the populations in descending order.
        for countries in countriesByContinent:
            populationList.insert(0, self._countryCat[countries]._c_pop)
        populationList = sorted(populationList, reverse=True)
        # Third for loop gets all the names of the countries belonging to the population list.
        for names in populationList:
            for key in self._countryCat:
                if self._countryCat[key]._c_pop == names:
                    nameList.append(key)
        # Merges the country name and population lists into one tuple.
        countriesByPopulation = tuple(zip(nameList, populationList))
        return countriesByPopulation

    # Allows the user to input a population, and returns a list of pairs(tuples) as country/population.
    # The list outputted will be in descending order from largest to smallest population.
    def getCountriesByArea(self):
        continent_input = str(input("Please input the continent that you would like to see the countries of (in order of descending area): "))
        # Stores a list of all countries in a selected continent.
        countriesByContinent = []
        # Stores a list of the country populations in order of largest to smallest.
        areaList = []
        # Stores a list of the country names in order of largest to smallest population (done using populationList).
        nameList = []
        # First for loop is used in the getCountriesByContinent method, finding all countries in a continent.
        for key in self._cDictionary:
            if self._cDictionary[key] == continent_input:
                countriesByContinent.append(key)
        # Second for loops gets all the areas in descending order.
        for countries in countriesByContinent:
            areaList.insert(0, self._countryCat[countries]._c_area)
        areaList = sorted(areaList, reverse=True)
        # Third for loop gets all the names of the countries belonging to the population list.
        for names in areaList:
            for key in self._countryCat:
                if self._countryCat[key]._c_area == names:
                    nameList.append(key)
        # Merges the country name and population lists into one tuple.
        countriesByArea = tuple(zip(nameList, areaList))
        return countriesByArea

    # Finds the continent with the highest population.
    def findMostPopulousContinent(self):
        population = {}
        highestContinent = ""
        highestPopulation = 0
        for key in self._cDictionary:
            population[self._cDictionary[key]] = 0
        for key in self._cDictionary:
            population[self._cDictionary[key]] += self._countryCat[key]._c_pop
        for key in population:
            if population[key] >= highestPopulation:
                highestContinent = key
                highestPopulation = population[key]
        return highestContinent

    # Allows the user to input a population density range and return the countries within that range.
    # The list should be in order of highest to lowest density, and return as pairs (country name: population density)
    def filterCountriesByPopDensity(self):
        countryList = []
        # Get user input for the range:
        print("To obtain the countries within a certain population density range, please enter the upper and lower limits")
        highest_density = int(input("Please enter the upper limit: "))
        lowest_density = int(input("Please enter the lower limit: "))
        # Looks through the country catalogue
        for countries in self._countryCat:
            # Using the method in the country.py file
            populationDensity = self._countryCat[countries].getPopDensity(self._countryCat[countries]._c_pop, self._countryCat[countries]._c_area)
            # Confirms that the country is within the population density range.
            if lowest_density <= populationDensity <= highest_density:
                countryList.append(countries)
        return countryList

    # Saves catalogue to an output file
    def saveCountryCatalogue(self, file_name):
        # Opens the  catalogue file
        file = open(file_name, "w")
        # This for loops looks through each country and sorts them alphabetically.
        for country in sorted(self._countryCat):
            try:
                rounded_number = round(self._countryCat[country]._c_pop / self._countryCat[country]._c_area, 2)
                file.write(str(self._countryCat[country]._c_name) + "|" + str(self._countryCat[country]._c_continent) + "|" + str(self._countryCat[country]._c_pop) + "|" + str(self._countryCat[country]._c_area) + "|" + str(rounded_number) + "\n")
            except:
                return "-1"
        file.close()

def main():
    cc = CountryCatalogue('continent.txt', 'data.txt')
    print(cc.saveCountryCatalogue('save.txt'))

main()


