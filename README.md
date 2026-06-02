# SATTS Irrigation - Edge Computing 🛰️🌱

**Disciplina:** Edge Computing & Computer Systems  
**Professores:** Paulo Marcotti e Lucas Demetrius  
**Semestre:** 1º Semestre - Global Solution  

---

## 📋 Descrição do Projeto
O **SATTS (Sistema de Gestão de Irrigação Baseado em Dados Orbitais)** é uma plataforma voltada para a otimização de recursos hídricos na agricultura. Enquanto o núcleo do sistema utiliza dados de satélite para previsões macroclimáticas, este módulo de **Edge Computing** atua na "ponta" (diretamente na plantação). Utilizando um microcontrolador, o sistema realiza a leitura local da umidade e da qualidade do solo em tempo real, permitindo ações imediatas e automatizadas sem depender exclusivamente da conexão com a nuvem.

## 🎯 Objetivo da Solução
O objetivo principal é evitar o desperdício de água e prevenir a perda de safras por secas repentinas. Através da computação de borda, o protótipo analisa as condições do solo e aciona alertas visuais (Sistema de Semáforo LED), sonoros (Buzzer) e textuais (Display LCD) para informar o produtor sobre o momento exato em que a irrigação deve ser ativada.

## 🛠️ Componentes Utilizados
A montagem virtual no Tinkercad utilizou os seguintes componentes de hardware:
* 1x Placa Arduino Uno R3
* 1x Display LCD 16x2
* 1x Potenciômetro (utilizado para controle de contraste do display LCD)
* 2x Sensores Analógicos simulados (conectados nas portas A0 e A1 para representar a variação de *Umidade* e *Qualidade do Solo*)
* 3x LEDs (Verde, Amarelo e Vermelho)
* 1x Piezo (Buzzer para alertas sonoros)
* Resistores Diversos (para proteção dos LEDs)
* 1x Protoboard (Placa de ensaio) e Jumpers para conexão

## ⚙️ Explicação do Funcionamento
O cérebro do projeto (código em C++) lê os dados analógicos vindos dos sensores nas portas `A0` (Umidade) e `A1` (Solo) e aplica a seguinte lógica de negócios:

**Análise de Umidade (Porta A0):**
* **Nível > 700 (Ideal):** O LED Verde (Pino 8) acende. O LCD exibe `STATUS: IDEAL`. Nenhuma ação de irrigação é necessária.
* **Nível > 300 (Atenção):** O LED Amarelo (Pino 9) acende. O LCD exibe `STATUS: ALERTA`. O produtor deve ficar atento.
* **Nível < 300 (Crítico):** O LED Vermelho (Pino 10) acende e o Buzzer (Pino 7) emite bipes de alerta. O LCD exibe `STATUS: IRRIGAR`. 

**Análise do Solo (Porta A1):**
Paralelamente, o LCD informa a saúde geral do terreno na segunda linha da tela:
* `>= 650`: Exibe `SOLO: OTIMO`
* `>= 300`: Exibe `SOLO: MEDIO`
* `< 300`: Exibe `SOLO: RUIM`

## 🔌 Estrutura do Circuito e Instruções de Execução
Para testar e simular o funcionamento do projeto, siga as instruções abaixo:

1. Acesse o link do projeto no Tinkercad disponibilizado no fim deste documento.
2. Clique no botão **"Iniciar Simulação"** no canto superior direito da tela.
3. Observe a mensagem de inicialização no Display LCD ("SATTS SYSTEM").
4. Clique nos componentes que simulam os sensores (nas portas analógicas) e mova os controles deslizantes para alterar os valores de entrada.
5. Verifique a mudança de comportamento dos LEDs, a ativação do Buzzer e a atualização dos status na tela LCD conforme as regras de negócio descritas acima.
6. (Opcional) Abra o **Monitor Serial** na parte inferior da tela de código para ver os valores brutos (`Umidade: X | Solo: Y`) sendo impressos em tempo real.

## 👥 Integrantes do Grupo
* Felipe Santos – RM572382
* Gabriel Pereira – RM569222
* João Leão – RM569864
* Thomaz Vitorino – RM572801
* Yago Torigoe – RM569859

## 🔗 Simulação (Tinkercad)
Acesse a simulação funcional completa através do link abaixo:
👉 **[CLIQUE AQUI PARA ACESSAR A SIMULAÇÃO NO TINKERCAD]( [COLE_O_SEU_LINK_AQUI] )**
