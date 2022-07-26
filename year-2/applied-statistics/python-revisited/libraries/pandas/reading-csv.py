import pandas as pd

df = pd.read_csv('C:\\Users\\Volt\\Code\\AIML-Year-2\\applied-statistics\\python-revisited\\libraries\\pandas\\pokemon_data.csv')

# Prints the entire dataset
print(df)

top_results = df.head(5)

# Prints top 5 results
print(top_results)