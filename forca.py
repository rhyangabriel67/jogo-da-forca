palavras = ["CASA", "CARRO", "GATO", "ESCOLA", "BOLA"]
palavra = random.choice(palavras)

letras_corretas = []
letras_erradas = []
tentativas = 6

print("=== JOGO DA FORCA ===")

while tentativas > 0:
    print("\nPalavra: ", end="")

    for letra in palavra:
        if letra in letras_corretas:
            print(letra, end=" ")
        else:
            print("_", end=" ")

    print("\nTentativas restantes:", tentativas)
    print("Letras erradas:", letras_erradas)

    if all(letra in letras_corretas for letra in palavra):
        print("\nParabéns! Você venceu!")
        break

    letra = input("Digite uma letra: ").strip().upper()

    if len(letra) != 1 or not letra.isalpha():
        print("Digite apenas uma letra!")
        continue

    if letra in letras_corretas or letra in letras_erradas:
        print("Você já tentou essa letra!")
        continue

    if letra in palavra:
        letras_corretas.append(letra)
        print("Você acertou!")
    else:
        letras_erradas.append(letra)
        tentativas -= 1
        print("Você errou!")

else:
    print("\nVocê perdeu!")

print("A palavra era:", palavra)
