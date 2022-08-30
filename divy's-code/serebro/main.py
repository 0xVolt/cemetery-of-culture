from typing import List
from isbntools.app import*
import nltk
from nltk.stem.lancaster import LancasterStemmer
stemmer= LancasterStemmer()
import numpy
from tensorflow.python.framework import ops

import tflearn
import tensorflow
import random
import json
import pickle
with open("intents.json") as file:
    data=json.load(file)


words= []
labels= []
docs_x= [] # For every entry in docs_x we would have a corresponding mapping in docs_y
docs_y= [] #for every entry in docs_y we would have a corresponding mapping in docs_x

for intent in data["intents"]:
    for pattern in intent["patterns"]:
        wrds= nltk.word_tokenize(pattern)
        words.extend(wrds) #used to add a new entry or iterator at the end of the list
        docs_x.append(wrds)#will add 'words' in the list 'docs_x'
        docs_y.append(intent["tag"])# for every word in docs_x we would have a corresponding tag in docs_y

    if intent["tag"] not in labels:
            labels.append(intent["tag"]) #initialising all the tags into the list labels
    
try:
    
    with open("data.pickle", "rb") as f:
        words,labels,training,output = pickle.load(f)



except:

    words= [stemmer.stem(w.lower())for w in words if w != "?"]
    words= sorted(list(set(words))) #to remove duplicate syllables extracted from .word_tokenize function
    labels = sorted(labels) #this will sort all the tags stored in labels 
    training= []
    output= []

    out_empty = [0 for _ in range(len(labels))] 

    for x, doc in enumerate(docs_x):
        bag=[]
        wrds= [stemmer.stem(w) for w in doc] #we never stemmed wrds so we are doing it now
        
        for w in words:
            if w in wrds:
                bag.append(1)
            else:
                bag.append(0)
        
        output_row = out_empty[:]
        output_row[labels.index(docs_y[x])] = 1
        training.append(bag)
        output.append(output_row)

    training= numpy.array(training)
    output= numpy.array(output)
    with open("data.pickle", "wb") as f:
        pickle.dump((words,labels,training,output), f)


ops.reset_default_graph()

net= tflearn.input_data(shape=[None, len(training[0])])
net= tflearn.fully_connected(net, 8)
net= tflearn.fully_connected(net, 8)
net= tflearn.fully_connected(net, len(output[0]), activation="softmax")
net= tflearn.regression(net)
model = tflearn.DNN(net)



model.fit(training, output, n_epoch=1000, batch_size=8, show_metric=True)
model.save("model.tflearn")


def bag_of_words(s,words):
    bag=[0 for _ in range(len(words))]
    s_words = nltk.word_tokenize(s)
    s_words= [stemmer.stem(word.lower()) for word in s_words]

    for se in s_words:
        for i,w in enumerate(words):
            if w==se:
                bag[i]=1

    return numpy.array(bag)

    

def chat():
    sell=[]
    borrow=[]
    def switchIntents(tag):
        for tg in data["intents"]:
            if tg['tag']==tag:
                                                                              
                responses=tg['responses']
                print(random.choice(responses))

    print("start talking with the bot!")
    while True:
        inp= input("you: ")
        if inp.lower()=="quit":
            break

        result = model.predict([bag_of_words(inp, words)])[0]
        result_index= numpy.argmax(result)
        tag = labels[result_index]
        
        if result[result_index]>0.7:

            for tg in data["intents"]:
                if tg['tag']==tag:
                    responses = tg['responses']
                    print(random.choice(responses))

            if tag=="help":
                print("Enter your choice and get help from me :D")
                n= int(input(""))
                if n==1:
                    tag="complaints"
                    switchIntents(tag)
                    
                           
                    f=int(input(""))
                    if f==1:
                        tag="Fraud"
                        count=0
                        switchIntents(tag)
                            
                    elif f==2:
                        tag="transactional"
                        switchIntents(tag)


                    elif f==3:
                        tag="BookList"
                        switchIntents(tag)

                elif n==2:
                    print("Enter the ISBN number of the book")
                    isbn=(input(""))
                    print("The details of the book is ")
                    try:
                        print(registry.bibformatters['Author'](meta(isbn)))
                        print("Is this the book you want to sell?  [y/n]")
                        res=input("")
                        if res=="y":
                            print("The book will be queued to sell after you will upload the pictures of the book")


                        
                    except:
                        print("Cannot Find the ISBN number hence cannot sell")
                
                #elif n==3:





                
                    
                





                                            
                                        

                            

                                                           
                
                
                    
                        
                
                
                
            else:
                continue
        else:
            print("I didn't understand you, try again :D")

chat()


