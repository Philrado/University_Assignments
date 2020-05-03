class Country:
    # Initializes instance variables with proper types.
    def __init__(self, name, pop, area, continent):
        self._c_name = name
        self._c_pop = pop
        self._c_area = area
        self._c_continent = continent

    # Setter Methods
    def setPopulation(self, pop):
        self._c_pop = pop
    def setArea(self, area):
        self._c_area = area
    def setContinent(self, continent=""):
        self._c_continent = continent

    # Getter Methods
    def getName(self):
        return self._c_name
    def getPopulation(self):
        return self._c_pop
    def getArea(self):
        return self._c_area
    def getContinent(self):
        return self._c_continent

    # Calculates the population density.
    def getPopDensity(self, pop, area):
        self._c_PopDensity = round(pop/area, 2)
        return self._c_PopDensity

    # Generates a string representation of the values in this class.
    def __repr__(self):
        return self._c_name + " (pop: " + str(self._c_pop) + ", size: " + str(self._c_area) + ") in " + self._c_continent

