# STM32CubeMX - TIM4 PWM Configuration Guide

## Step-by-Step Instructions for Configuring TIM4 Channel 1 as PWM

### Step 1: Enable Timer Mode
1. In STM32CubeMX, click on **"Timers"** in the left sidebar (or find TIM4 in the peripheral list)
2. Click on **"TIM4"**
3. You'll see the "Mode" section at the top

### Step 2: Set Channel to PWM Generation Mode
In the **"Mode"** section:
1. Find **"Channel 1"** (since you're using PB6 = TIM4_CH1)
2. Click the dropdown next to "Channel 1"
3. Select **"PWM Generation CH1"**

**Options you'll see:**
- Input Capture direct mode
- Input Capture indirect mode
- Output Compare CH1
- **PWM Generation CH1** ← Select this
- PWM Generation CH1 CH1N
- One Pulse Mode

### Step 3: Configure PWM Parameters
After enabling PWM Generation, go to the **"Configuration"** tab (below the Mode section):

#### 3.1 Parameter Settings Tab
Click on **"Parameter Settings"** - you'll see:

**Counter Settings:**
- **Prescaler (PSC)**: Set based on desired PWM frequency
- **Counter Mode**: Up (default is fine)
- **Counter Period (AutoReload Register - ARR)**: Set based on desired PWM resolution
- **Internal Clock Division**: No Division (default)
- **Repetition Counter**: 0 (default)
- **Auto-reload preload**: Enable (recommended)

**PWM Generation Channel 1:**
- **Mode**: PWM mode 1 (default - output high when CNT < CCR)
- **Pulse (CCR1 value)**: Initial duty cycle value (0 to ARR)
- **Output compare preload**: Enable (recommended)
- **Fast Mode**: Disable (unless you need it)
- **CH Polarity**: High (default - active high)

### Step 4: Calculate Prescaler and Period Values

For your stepper motor application, you need to determine:

**PWM Frequency Formula:**
```
PWM_Frequency = Timer_Clock / ((PSC + 1) × (ARR + 1))
```

**Example 1: 10 kHz PWM with good resolution**
Assuming System Clock = 170 MHz (after you configure PLL):
- Timer Clock (TIM4 is on APB1) = 170 MHz
- Target PWM Frequency = 10 kHz
- Desired Resolution = 1000 steps (0-999)

```
Prescaler (PSC) = 16 (so divisor = 17)
ARR = 999

PWM_Freq = 170,000,000 / (17 × 1000) = 10,000 Hz ✓
Resolution = 1000 steps (0.1% duty cycle precision)
```

**Settings:**
- Prescaler: **16**
- Counter Period (ARR): **999**
- Pulse (initial): **500** (50% duty cycle)

**Example 2: 20 kHz PWM (higher frequency, less resolution)**
```
Prescaler (PSC) = 16
ARR = 499

PWM_Freq = 170,000,000 / (17 × 500) = 20,000 Hz
Resolution = 500 steps
```

**Settings:**
- Prescaler: **16**
- Counter Period (ARR): **499**
- Pulse (initial): **250** (50% duty cycle)

**Example 3: For current 16 MHz system clock (before PLL config)**
```
Timer Clock = 16 MHz
Target = 10 kHz
Prescaler = 0 (divisor = 1)
ARR = 1599

PWM_Freq = 16,000,000 / (1 × 1600) = 10,000 Hz
Resolution = 1600 steps
```

### Step 5: Recommended Settings for Stepper Motor

**For DM556Y Motor Driver (typical stepper requirements):**
- **Frequency**: 1 kHz to 200 kHz (most steppers work well at 10-50 kHz)
- **Duty Cycle**: Usually 50% (many drivers only care about edges)
- **Resolution**: 100-1000 steps is plenty for stepper control

**Recommended Configuration (assuming 170 MHz system clock):**
```
Mode: PWM Generation CH1
Prescaler (PSC): 16
Counter Period (ARR): 999
Pulse (CCR1): 500
Mode: PWM mode 1
CH Polarity: High
Output compare preload: Enable
Auto-reload preload: Enable
```

This gives you:
- **10 kHz PWM frequency**
- **1000 steps of resolution** (0-999)
- **50% initial duty cycle**

### Step 6: GPIO Settings (Should Auto-Configure)
After setting PWM mode, the GPIO pin (PB6) should automatically configure as:
- **Mode**: Alternate Function
- **GPIO Pull-up/Pull-down**: No pull-up and no pull-down
- **GPIO Speed**: Can set to Medium or High (High for faster edges)
- **Maximum output speed**: High (for clean square waves)

You can verify/adjust this in:
- **Pinout & Configuration** → Click on PB6 → Check settings

### Step 7: Advanced Settings (Optional)

#### If you need to change PWM frequency dynamically:
In the **NVIC Settings** tab:
- You can enable **TIM4 global interrupt** if you want to update PWM parameters in an ISR
- Usually not needed for basic stepper control

#### If you need complementary output (you don't):
- TIM4 doesn't support complementary outputs (that's for TIM1/TIM8)
- You're good with just CH1 output

### Step 8: Generate Code
1. Click **"Project"** → **"Generate Code"** (or Ctrl+S and generate)
2. CubeMX will create the initialization code in `tim.c`

### Step 9: Verify Generated Code

Look for this in `tim.c`:
```c
void MX_TIM4_Init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 16;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 999;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  
  // ... clock and master config ...
  
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 500;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1);
}
```

### Step 10: Start PWM in Your Code

In your `main.c`, after `MX_TIM4_Init()`:

```c
// In main() function, after peripheral initialization
HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
```

### Step 11: Change Duty Cycle Dynamically (in your code)

```c
// Set duty cycle to 75% (750 out of 999)
__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 750);

// Set duty cycle to 25% (250 out of 999)
__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 250);

// Set to 0% (off)
__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);

// Set to 100% (full on)
__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 999);
```

### Step 12: Change PWM Frequency Dynamically (if needed)

```c
// Stop PWM first
HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);

// Change frequency by changing ARR
__HAL_TIM_SET_AUTORELOAD(&htim4, 499);  // New period

// Adjust duty cycle proportionally if needed
__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 250);  // 50% of new period

// Restart PWM
HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
```

---

## Quick Reference Summary

### CubeMX Settings:
| Parameter | Value | Notes |
|-----------|-------|-------|
| Timer | TIM4 | |
| Channel 1 Mode | PWM Generation CH1 | |
| Prescaler | 16 | Adjust for clock freq |
| Counter Period (ARR) | 999 | Gives 1000 steps |
| Pulse (CCR1) | 500 | 50% duty cycle |
| PWM Mode | PWM mode 1 | High when CNT < CCR |
| Polarity | High | Active high output |
| Preload | Enable | Smooth updates |

### Code Usage:
```c
// Start PWM
HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);

// Set duty cycle (0-999)
__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, duty_value);

// Stop PWM
HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
```

---

## Notes for Stepper Motor Control

**Important:** For stepper motor control with the DM556Y:
- The driver responds to **pulse edges** (rising or falling)
- **Duty cycle doesn't matter** (50% is standard)
- **Frequency** determines step rate: steps/sec = PWM_frequency
- You'll likely use a **variable frequency PWM** (not fixed 10kHz)

**Example:** To move 1000 steps/second, set PWM to 1 kHz

You may want to implement **frequency ramping** for acceleration/deceleration:
```c
void SetStepFrequency(uint32_t steps_per_sec)
{
    uint32_t timer_clock = 170000000;  // 170 MHz
    uint32_t prescaler = 16 + 1;       // PSC + 1
    
    // Calculate ARR for desired frequency
    uint32_t arr = (timer_clock / (prescaler * steps_per_sec)) - 1;
    
    HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
    __HAL_TIM_SET_AUTORELOAD(&htim4, arr);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, arr / 2);  // 50% duty
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
}
```

---

## Troubleshooting

**Problem: No PWM output on PB6**
- Check: Did you call `HAL_TIM_PWM_Start()`?
- Check: Is GPIO configured as Alternate Function?
- Check: Is timer clock enabled?
- Check: Is CCR1 value > 0 and < ARR?

**Problem: Wrong frequency**
- Check: Verify actual timer clock frequency
- Check: PSC and ARR calculations
- Measure with oscilloscope

**Problem: PWM not updating smoothly**
- Enable auto-reload preload
- Enable output compare preload
- Updates happen on timer overflow

---

## Screenshot Navigation in CubeMX

1. **Pinout & Configuration** (left sidebar)
2. **Timers** → **TIM4**
3. **Mode** section (top):
   - Channel 1: **PWM Generation CH1**
4. **Configuration** section (bottom):
   - **Parameter Settings** tab
   - Set Prescaler, Period, Pulse values

**That's it!** You should now have a working PWM output on PB6.
