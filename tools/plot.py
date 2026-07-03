import numpy as np
import matplotlib.pyplot as plt
from pathlib import Path
import csv

ROOT_DIR = Path(__file__).parent.parent
DATA_DIR = ROOT_DIR / "data"
SAVE_DIR = ROOT_DIR / "plots"


# Standardized figure sizes in inches

FIG_STANDARD = (6.5, 4.0)
FIG_WIDE = (7.5, 3.5)
FIG_SQUARE = (5.0, 5.0)


def extract_csv(file_dir):
    x, y = [], []

    with open(file_dir) as file:
        file_reader = csv.reader(file)

        for row in file_reader:
            if len(row) >= 2:
                x.append(float(row[0]))
                y.append(float(row[1]))

    return (np.array(x), np.array(y))


def save_graph(x, y, fig_size: tuple[float, float], func_name: str, file_name: str):
    """File name must include either .png or .pdf"""

    fig, ax = plt.subplots(figsize=fig_size)

    ax.axvline(x=0, linewidth=0.7, color="black")
    ax.axhline(y=0, linewidth=0.7, color="black")
    ax.set_xlabel("x-axis")
    ax.set_ylabel("y-axis")
    ax.grid(True)

    ax.plot(x, y, label=func_name)
    ax.legend()

    fig.savefig(SAVE_DIR / file_name, dpi=300, bbox_inches="tight")
    print("successfully generated plot")


# Example usage

x, y = extract_csv(DATA_DIR / "sin_reference.csv")
save_graph(x, y, FIG_STANDARD, "$ y = sin(x) $", "sin_reference_figure.pdf")

x, y = extract_csv(DATA_DIR / "cos_reference.csv")
save_graph(x, y, FIG_STANDARD, "$ y = cos(x) $", "cos_reference_figure.pdf")

x, y = extract_csv(DATA_DIR / "sin_taylor.csv")
save_graph(x, y, FIG_STANDARD, "$ y = sin(x) $", "sin_taylor_figure.pdf")

x, y = extract_csv(DATA_DIR / "cos_taylor.csv")
save_graph(x, y, FIG_STANDARD, "$ y = cos(x) $", "cos_taylor_figure.pdf")
