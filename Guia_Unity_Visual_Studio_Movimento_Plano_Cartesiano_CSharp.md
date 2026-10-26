---
title: "Guia passo a passo: Unity + Visual Studio + C#"
---

**Criando um objeto que se movimenta no plano cartesiano**

Objetivo: criar um projeto 3D na Unity, adicionar um objeto (um cubo),
configurar o Visual Studio como editor de código e programar o movimento
do objeto nos eixos X e Z usando C#. O documento explica tanto a
interface quanto a lógica dos comandos.

# 1. O que você vai usar

-   Unity Hub: instala e organiza os projetos e versões da Unity.

-   Unity Editor: cria a cena, objetos, componentes, câmera, iluminação
    e executa o jogo.

-   Visual Studio: escreve e depura o código C#.

-   C#: linguagem usada pelos scripts da Unity.

-   Um teclado: usaremos W/A/S/D ou as setas para movimentação.

# 2. Entendendo o plano cartesiano 3D da Unity

Em um projeto 3D, a Unity trabalha com três eixos:

-   X = esquerda/direita.

-   Y = cima/baixo.

-   Z = frente/trás.

Para um personagem andando sobre um chão horizontal, normalmente
mantemos Y constante e alteramos X e Z. Assim, o movimento acontece
sobre o plano XZ.

Exemplo: uma posição (3, 0, 5) significa X=3, Y=0 e Z=5.

Importante: em matemática escolar, é comum chamar o plano horizontal de
XY. Na Unity 3D, o chão normalmente é XZ porque Y representa a altura.

# 3. Criar o projeto na Unity Hub

1.  Abra o Unity Hub.

2.  Clique em New project / Novo projeto.

3.  Escolha um template 3D. Para este exercício, o template 3D Core é
    suficiente.

4.  Dê um nome ao projeto, por exemplo: MovimentoPlanoCartesiano.

5.  Escolha uma pasta onde o projeto será salvo.

6.  Clique em Create project / Criar projeto.

A Unity abrirá o Editor. Dependendo da versão instalada, os nomes ou
posições de alguns botões podem mudar levemente.

# 4. Conhecendo as principais áreas da interface

-   Hierarchy (Hierarquia): lista os objetos que existem na cena.

-   Scene (Cena): área onde você monta e visualiza o mundo do jogo.

-   Game (Jogo): mostra o que a câmera do jogo enxerga.

-   Inspector (Inspetor): mostra e permite alterar componentes do objeto
    selecionado.

-   Project (Projeto): mostra arquivos, pastas, scripts, materiais e
    outros recursos.

-   Console: mostra erros, avisos e mensagens do código.

-   Play: executa a cena para testar o jogo.

# 5. Criar o chão

7.  Na Hierarchy, clique com o botão direito em uma área vazia.

8.  Escolha 3D Object \> Plane.

9.  Selecione o Plane.

10. No Inspector, procure Transform.

11. Em Position, coloque X=0, Y=0, Z=0.

12. Em Scale, pode usar X=5, Y=1, Z=5 para deixar o chão maior.

O Plane serve como referência visual para perceber o deslocamento do
objeto.

# 6. Criar o objeto que será controlado

13. Na Hierarchy, clique com o botão direito.

14. Escolha 3D Object \> Cube.

15. Selecione o Cube.

16. No Transform, coloque Position X=0, Y=0.5, Z=0.

17. Renomeie o objeto para Player, usando F2 ou o botão direito \>
    Rename.

Colocar Y=0.5 faz o centro do cubo ficar acima do chão, evitando que
metade dele fique dentro do Plane.

# 7. Entender o Transform antes de programar

Todo GameObject possui um componente Transform. Ele guarda
principalmente:

-   Position: posição do objeto no mundo (X, Y, Z).

-   Rotation: rotação do objeto.

-   Scale: tamanho do objeto.

O nosso script vai alterar a Position. Não precisamos criar manualmente
uma variável para a posição do Player porque a Unity já fornece
transform.position.

# 8. Preparar o Visual Studio

Durante a instalação do Visual Studio, instale a carga de trabalho de
desenvolvimento de jogos com Unity, quando disponível na sua versão do
instalador. Ela instala os componentes necessários para trabalhar com
projetos Unity e C#.

18. Abra o Visual Studio Installer.

19. Localize sua instalação do Visual Studio e clique em
    Modify/Modificar.

20. Procure a carga de trabalho relacionada a Game development with
    Unity/Desenvolvimento de jogos com Unity.

21. Marque-a e instale/aplique as alterações.

22. Abra a Unity.

23. Nas preferências/configurações da Unity, procure a seção de
    ferramentas externas (External Tools).

24. Em External Script Editor, selecione Visual Studio.

O texto exato dos menus pode variar entre versões da Unity e do Visual
Studio. O ponto importante é que o editor de script externo esteja
definido como Visual Studio.

# 9. Criar o script C#

25. Na janela Project, crie uma pasta chamada Scripts para manter o
    projeto organizado.

26. Entre na pasta Scripts.

27. Clique com o botão direito \> Create \> C# Script.

28. Dê ao script o nome PlayerMovement.

29. O nome do arquivo deve ser PlayerMovement.cs.

30. Arraste o script da janela Project para o objeto Player na
    Hierarchy. Alternativamente, com o Player selecionado, use Add
    Component e procure o script.

31. Dê duplo clique no script para abrir o Visual Studio.

# 10. Primeiro código: movimento no plano XZ

> using UnityEngine;\
> \
> public class PlayerMovement : MonoBehaviour\
> {\
> public float velocidade = 5f;\
> \
> void Update()\
> {\
> float x = Input.GetAxisRaw(\"Horizontal\");\
> float z = Input.GetAxisRaw(\"Vertical\");\
> \
> Vector3 movimento = new Vector3(x, 0f, z);\
> \
> transform.position += movimento \* velocidade \* Time.deltaTime;\
> }\
> }

Observação: este exemplo usa o sistema de entrada clássico da Unity
(Input Manager). Se o seu projeto estiver configurado exclusivamente
para o novo Input System, pode ser necessário habilitar o sistema antigo
nas configurações de Player ou adaptar o script para o novo Input
System.

# 11. Explicação linha por linha

using UnityEngine;

Importa as classes principais da Unity. É isso que permite usar
MonoBehaviour, Vector3, Input, Time e outros recursos.

public class PlayerMovement : MonoBehaviour

Cria uma classe chamada PlayerMovement. O \': MonoBehaviour\' permite
que essa classe seja usada como um componente de um GameObject e dá
acesso a métodos como Update().

public float velocidade = 5f;

Cria uma variável pública chamada velocidade. \'float\' é um número
decimal. O valor 5f é a velocidade inicial. Como ela é public, aparece
no Inspector e pode ser alterada sem editar o código.

void Update()

Update é chamado pela Unity uma vez a cada frame. É adequado para
verificar entrada do jogador e atualizar o movimento continuamente.

float x = Input.GetAxisRaw(\"Horizontal\");

Lê o eixo horizontal. Normalmente A/Seta Esquerda produz -1, D/Seta
Direita produz +1 e sem entrada produz 0.

float z = Input.GetAxisRaw(\"Vertical\");

Lê o eixo vertical. Normalmente S/Seta Baixo produz -1, W/Seta Cima
produz +1 e sem entrada produz 0.

Vector3 movimento = new Vector3(x, 0f, z);

Cria um vetor tridimensional. X recebe o movimento horizontal, Y fica 0
para não subir/descer, e Z recebe o movimento para frente/trás.

transform.position += movimento \* velocidade \* Time.deltaTime;

Adiciona o deslocamento à posição atual. Time.deltaTime representa o
tempo decorrido desde o último frame. Isso evita que a velocidade
dependa diretamente da quantidade de FPS.

# 12. Como o plano cartesiano aparece na prática

Imagine o Player começando em (0, 0.5, 0). Se você apertar D, x será
positivo e o Player irá para a direita, aumentando X. Se apertar A, X
diminui. W aumenta Z e S diminui Z.

Tabela de exemplo:

  -----------------------------------------------------------------------
  Tecla             X                 Z                 Efeito
  ----------------- ----------------- ----------------- -----------------
  D / →             +1                0                 Vai para +X

  A / ←             -1                0                 Vai para -X

  W / ↑             0                 +1                Vai para +Z

  S / ↓             0                 -1                Vai para -Z
  -----------------------------------------------------------------------

# 13. Testar o jogo

32. Salve o script no Visual Studio (Ctrl+S).

33. Volte para a Unity e espere a compilação terminar.

34. Verifique a janela Console. Se houver erro vermelho, corrija o erro
    antes de testar.

35. Clique no botão Play na parte superior da Unity.

36. Clique na janela Game para garantir que ela está recebendo o
    teclado.

37. Pressione W, A, S e D ou as setas.

38. Observe o Player se movimentando sobre o Plane.

39. Clique novamente em Play para sair do modo de execução.

Alterações feitas durante o Play Mode normalmente são temporárias e
podem ser perdidas quando você sai do modo Play.

# 14. Como acompanhar X, Y e Z no Inspector

40. Entre no Play Mode.

41. Selecione o Player na Hierarchy.

42. Observe Transform \> Position no Inspector.

Você verá os valores de X, Y e Z mudando enquanto o objeto anda. X muda
com A/D, Z muda com W/S e Y permanece aproximadamente 0.5.

# 15. Por que usar Time.deltaTime?

Sem Time.deltaTime, o código poderia mover o objeto uma quantidade fixa
a cada frame. Um computador que renderiza 120 FPS executaria muito mais
frames por segundo do que um que renderiza 30 FPS, fazendo o objeto se
deslocar em velocidades diferentes.

Com deltaTime, a velocidade é baseada no tempo. A ideia simplificada é:

> deslocamento = direção × velocidade × tempo_do_frame

Por isso, se velocidade=5, a intenção é aproximadamente 5 unidades por
segundo, não 5 unidades por frame.

# 16. Exercício: transformar o movimento em um verdadeiro limite de plano

Você pode limitar a área onde o Player pode andar. Por exemplo, permitir
X entre -10 e +10 e Z entre -10 e +10.

> using UnityEngine;\
> \
> public class PlayerMovement : MonoBehaviour\
> {\
> public float velocidade = 5f;\
> \
> void Update()\
> {\
> float x = Input.GetAxisRaw(\"Horizontal\");\
> float z = Input.GetAxisRaw(\"Vertical\");\
> \
> Vector3 movimento = new Vector3(x, 0f, z);\
> \
> transform.position += movimento \* velocidade \* Time.deltaTime;\
> \
> Vector3 posicao = transform.position;\
> \
> posicao.x = Mathf.Clamp(posicao.x, -10f, 10f);\
> posicao.z = Mathf.Clamp(posicao.z, -10f, 10f);\
> \
> transform.position = posicao;\
> }\
> }

Mathf.Clamp(valor, mínimo, máximo) impede que um valor fique abaixo do
mínimo ou acima do máximo.

# 17. Um problema importante: movimento diagonal

Com o código básico, pressionar W+D cria o vetor (1, 0, 1). A magnitude
desse vetor é maior que a de (1, 0, 0), então o Player pode andar mais
rápido na diagonal.

Uma correção simples é normalizar o vetor:

> Vector3 movimento = new Vector3(x, 0f, z);\
> \
> if (movimento.magnitude \> 1f)\
> {\
> movimento.Normalize();\
> }\
> \
> transform.position += movimento \* velocidade \* Time.deltaTime;

Normalize mantém a direção, mas transforma a magnitude do vetor em 1.
Assim, diagonais não ficam mais rápidas.

# 18. Erros comuns e como resolver

-   O script não aparece no Player: verifique se o arquivo se chama
    PlayerMovement.cs e a classe se chama PlayerMovement.

-   Há erro vermelho no Console: abra o Console e leia a primeira
    mensagem de erro; um erro de compilação pode impedir scripts de
    funcionar.

-   O Player não se move: verifique se o script está anexado ao Player e
    se a janela Game está recebendo o teclado.

-   Input.GetAxisRaw dá erro ou não funciona: confira as configurações
    do sistema de entrada do projeto.

-   O objeto cai: se você adicionar Rigidbody, a física passa a
    controlar a posição. Para este primeiro exercício, não é necessário
    Rigidbody.

-   O Player atravessa o chão: sem física/collider, o objeto pode
    atravessar outros objetos. Para uma primeira demonstração de
    coordenadas isso é esperado.

-   Visual Studio não abre ao clicar no script: confira External Script
    Editor nas configurações da Unity e a instalação dos componentes de
    desenvolvimento Unity.

# 19. Estrutura final do projeto

> Assets/\
> ├── Scenes/\
> │ └── SampleScene.unity\
> └── Scripts/\
> └── PlayerMovement.cs

É recomendável criar pastas como Scenes, Scripts, Materials, Prefabs e
Art conforme o projeto crescer.

# 20. Próximos passos para evoluir o projeto

-   Adicionar câmera que acompanha o Player.

-   Adicionar colisões com paredes usando Collider.

-   Adicionar Rigidbody e trabalhar com física.

-   Criar um mapa maior.

-   Adicionar animação ao personagem.

-   Adicionar uma variável de vida.

-   Criar inimigos.

-   Criar um sistema de pontuação.

-   Trocar o cubo por um personagem 3D.

-   Depois, estudar o novo Input System da Unity para criar controles
    mais completos.

# Resumo da lógica

> Teclado\
> ↓\
> Input.GetAxisRaw()\
> ↓\
> valores X e Z\
> ↓\
> Vector3 movimento\
> ↓\
> movimento × velocidade × deltaTime\
> ↓\
> transform.position\
> ↓\
> Player muda de coordenada no plano XZ

Resultado: você criou um objeto controlável na Unity usando C#, escreveu
o código no Visual Studio e entendeu como a entrada do teclado é
convertida em alterações nas coordenadas X e Z.
