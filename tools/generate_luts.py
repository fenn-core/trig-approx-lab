import mpmath as mp

mp.mp.dps = 50


def generate_lut(intervals: int) -> str:
    if intervals <= 0:
        raise ValueError("intervals value out of range")

    x = mp.linspace(0, mp.pi / 2, intervals + 1)
    y = [mp.sin(i) for i in x]

    lut = f"""static constexpr long double sin_quarter_lut_{intervals}[] = {{ \n"""

    for value in y:
        lut += f"{mp.nstr(value, 21)}L,\n"

    lut += "}; \n\n"

    return lut


lut_8 = generate_lut(8)
lut_16 = generate_lut(16)
lut_32 = generate_lut(32)
lut_64 = generate_lut(64)

with open("lut.txt", "w") as file:
    file.write(lut_8)
    file.write(lut_16)
    file.write(lut_32)
    file.write(lut_64)
