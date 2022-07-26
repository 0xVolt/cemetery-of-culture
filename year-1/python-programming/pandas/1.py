import pandas as pd

# Create a data frame where each co is a series
df = pd.DataFrame ( {
        "Name": [
            "test0",
            "test1",
            "test2"
        ],

        "Age": [20, 21, 22],

        "Course": ["maths", "physics", "history"]
    }
)

print("\nDisplaying data frame:")
print(df)

print(df.describe())