# %% [markdown]
# # Experiment 7 - Complete Pre-processing Pipeline
# 
# ---

# %% [markdown]
# # Import dependencies

# %%
import pandas as pd
import re

import nltk
from nltk.stem import PorterStemmer
from nltk.stem import WordNetLemmatizer
from nltk.corpus import stopwords

from sklearn.feature_extraction.text import CountVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import classification_report, accuracy_score
from sklearn.model_selection import train_test_split
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC

# %%
vectorizer = CountVectorizer(ngram_range=(2, 2))

# %% [markdown]
# # Load data

# %%
data = pd.read_csv(r'/home/volt/code/cemetery-of-culture/year-3/computational-linguistics/assets/data/stock-news-dataset.csv', encoding ='ISO-8859-1')
data

# %%
data.shape

# %%
data.columns

# %%
data.info()

# %%
data.isnull().sum()

# %%
data.shape[1]

# %% [markdown]
# # Extracting Data

# %% [markdown]
# Renaming the columns of the dataframe

# %%
indexList = [i for i in range(data.shape[1])]

newIndices = [str(i) for i in indexList]
data.columns = newIndices

data.head(2)

# %% [markdown]
# Replacing all the special characters of the sentences with spaces

# %%
data.replace("[^a-zA-Z]", " ",regex=True, inplace=True)
data.head(2)

# %%
y = data.iloc[:, 1]
X = data.iloc[:, 2:]

# %%
y

# %% [markdown]
# Merging all columns to form a list of sentences

# %%
sentences = []
for row in range(0, len(X.index)):
    sentences.append(' '.join(str(x) for x in X.iloc[row,:28]))
    
len(sentences)

# %% [markdown]
# # Processing Sentences

# %% [markdown]
# Applying all the `Pre-processing Level 1` steps to clean the data

# %%
stemmer = PorterStemmer()
lemmatizer = WordNetLemmatizer()

corpus = []

stopWords = set(stopwords.words('english'))

for sentence in sentences:
    # Convert the sentence to lowercase using REGEX
    for f in re.findall("([A-Z]+)", sentence):
        sentence = sentence.replace(f, f.lower())

    # Removing special characters and replacing them with a space
    # sentence = re.sub("[^A-Za-z0-9]", " ", sentence, 0, re.IGNORECASE)
    
    # From a single sentence, store all the words 
    words = nltk.word_tokenize(sentence)
    
    # Filter out all the stop words
    words = [word for word in words if word not in stopWords]
    
    # Stem each of the tweets
    words = [stemmer.stem(word) for word in words if word not in stopWords]
    
    # Lemmatize each of the tweets
    words = [lemmatizer.lemmatize(word) for word in words]
    
    # Append them to a list
    # Remake the sentences after removing the stop words
    corpus.append(' '.join(words))

# %%
len(corpus)

# %% [markdown]
# # Vectorizing Sentences

# %%
corpusVector = vectorizer.fit_transform(corpus)
corpusVector

# %% [markdown]
# # Splitting into Training and Testing

# %%
X_train, X_test, y_train, y_test = train_test_split(corpusVector, y, test_size=0.3, shuffle=True, random_state=42)

# %%
X_train.shape, X_test.shape

# %%
y_train.shape, y_test.shape

# %% [markdown]
# # Classifier Implementation

# %%
def displayScore(predicted):
    print(f'{classification_report(y_test, predicted)} \n\nAccuracy for the logistic regression classifier: {accuracy_score(y_test, predicted) * 100} %')

# %% [markdown]
# ## Logistic Regression

# %%
model = LogisticRegression(random_state=0).fit(X_train, y_train)

logisticRegressionPredicted = model.predict(X_test)

displayScore(logisticRegressionPredicted)

# %%
# model = make_pipeline(StandardScaler(), SVC(gamma='auto')).fit(X_train, y_train)
model = SVC(gamma='auto').fit(X_train, y_train)

linearSVMPredicted = model.predict(X_test)

displayScore(linearSVMPredicted)


