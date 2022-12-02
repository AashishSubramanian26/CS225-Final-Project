from urllib.request import urlopen
import requests
from bs4 import BeautifulSoup
import re
import csv
import numpy as np

class WebScrape():
    def __init__(self):
        self.parentLinks = []
        self.parentName = []
        self.childLinks = []
        self.childName = []
        self.weights = []
        self.startingIndex = []

    def scrapeWiki(self):

        url = 'https://en.wikipedia.org/wiki/Ladder'
        website_url = requests.get(url).text
        soup = BeautifulSoup(website_url, "lxml")

        parentLink = 'https://en.wikipedia.org/wiki/Ladder'
        parentTitle = 'Ladder'
        self.startingIndex.append(0)

        for link in soup.find_all('a'):
            if ((link.get('title') is not None) and (':' not in link.get('href'))):
                if ((':' not in link.get('title')) and ('?' not in link.get('href'))):
                    if (('Main_Page' not in link.get('href')) and ('identifier' not in link.get('title')) and (
                            'content' not in link.get('title'))):
                        if (link.get('title') not in self.childName):
                            self.parentLinks.append(parentLink)
                            self.parentName.append(parentTitle)
                            self.childLinks.append('https://en.wikipedia.org' + link.get('href'))
                            self.childName.append(link.get('title'))

        for i in range(1000):
            url = self.childLinks[i]
            website_url = requests.get(url).text
            soup = BeautifulSoup(website_url, "lxml")

            parentLink = url
            parentTitle = self.childName[i]
            self.startingIndex.append(len(self.childName))

            for link in soup.find_all('a'):
                if ((link.get('title') is not None) and (':' not in link.get('href'))):
                    if ((':' not in link.get('title')) and ('?' not in link.get('href'))):
                        if (('Main_Page' not in link.get('href')) and ('identifier' not in link.get('title')) and (
                                'content' not in link.get('title'))):
                            # if (link.get('title') not in self.childName):
                            self.parentLinks.append(parentLink)
                            self.parentName.append(parentTitle)
                            self.childLinks.append('https://en.wikipedia.org' + link.get('href'))
                            self.childName.append(link.get('title'))
        print(self.parentLinks)
        print(self.parentName)
        print(self.childLinks)
        print(self.childName)
        print(self.startingIndex)
        print(len(self.startingIndex))



        for j in range(len(self.parentLinks)):
            parentTitle = self.parentName[j];
            startIndexParent = self.parentName.index(parentTitle)
            #endIndexParent = self.startingIndex[self.startingIndex.index(startIndexParent) + 1] - 1
            if (startIndexParent == self.startingIndex[-1]):
                arr2 = self.childName[startIndexParent:]
                endIndexParent = len(arr2)
            else:
                endIndexParent = self.startingIndex[self.startingIndex.index(startIndexParent) + 1] - 1
            length = endIndexParent - startIndexParent
            self.weights.append(length)

        #print(self.parentName[7057])
        #self.createCSV()
        '''
        for j in range(len(self.parentLinks)):
            try:
                parentTitle = self.parentName[j];
                startIndexParent = self.parentName.index(parentTitle)
                endIndexParent = self.startingIndex[self.startingIndex.index(startIndexParent) + 1]-1

                childTitle = self.childName[j];
                startIndexChild = self.parentName.index(childTitle)
                print(startIndexChild)

                if(startIndexChild == self.startingIndex[-1]):
                    arr2 = self.childName[startIndexChild:]
                else:
                    temp89 = self.startingIndex.index(startIndexChild) + 1
                    #print(temp89)
                    endIndexChild = self.startingIndex[temp89]-1
                    arr2 = self.childName[startIndexChild: endIndexChild]

                arr1 = self.childName[startIndexParent:endIndexParent]
                #arr2 = self.childName[startIndexChild: endIndexChild]
                #print(arr2)
                # use np.intersect1d(array1, array2) for the weight. this will return a new array
                # we can use size to get how many elements are in the array and that will be our weight
                arr3 = np.intersect1d(arr1, arr2)
                self.numLinksShared.append(len(arr3))

            except:
                print("Fuck this")


        '''

        '''
        parentTitle = self.parentName[700];
        startIndexParent = self.parentName.index(parentTitle)
        endIndexParent = self.startingIndex[self.startingIndex.index(startIndexParent) + 1]-1
        '''
        #print(startIndexParent)
        #print(endIndexParent)
        #array1 holds child titles starting 0 to the end
        '''
        
        #Paris child links: 0-2220

        #Next set of child links: 2221-2332

        array 1 = self.Childnames[0:2220]

        array 2 = self.Childnames[2221:2332]

        #array holds
        '''

    def createCSV(self):
        datafile = open("Dataset.csv", "w")
        print("Hello")
        writer = csv.writer(datafile)
        writer.writerow(['Parent Link', 'Parent Title', 'Child Link', 'Child Title, Weights'])  # added
        print(len(self.weights))
        print(len(self.parentName))
        for i in range(len(self.parentName)):
            writer.writerow([self.parentLinks[i].encode(encoding='UTF-8', errors='strict'),
                             self.parentName[i].encode(encoding='UTF-8', errors='strict'),
                             self.childLinks[i].encode(encoding='UTF-8', errors='strict'),
                             self.childName[i].encode(encoding='UTF-8', errors='strict'),
                             self.weights[i]])

        datafile.close()
        print('hello')


d = WebScrape()
d.scrapeWiki()
d.createCSV()
