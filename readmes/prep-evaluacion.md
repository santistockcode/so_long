# Table of contents
1. [Project overview](#project-overview)
2. [Tests](#tests)
3. [Memoria](#memoria)
4. [Visual map](#visual-map)
5. [Functions tree](#functions-tree)
6. [Theory](#theory)
7. [Evaluations](#evaluations)
8. [Further study](#further-study)

## Project overview
## Tests
https://github.com/gemartin99/So_long-Tester
### My own tests
### Francinette
To test from github codespace use
```bash
/home/codespace/francinette/tester.sh
```
## Memoria
## Visual map
## Functions tree
## Theory
#### https://github.com/42-Fundacion-Telefonica/MLX42
##### Basics
    initialization, building, link, debug
##### Colors
Colors are often represented in hexadecimal because it allows for a compact representation of the red, green, blue, and alpha (RGBA) components of a color. For example, the color red with full opacity can be represented as 0xFF0000FF:

    0xFF (red component)
    0x00 (green component)
    0x00 (blue component)
    0xFF (alpha component)
Bytes and Bitwise Operations
In the context of setting pixel colors, each color component (red, green, blue, alpha) is typically one byte (8 bits). A 32-bit integer (4 bytes) can hold all four components. Bitwise operations are used to extract and set these components.

MLX42.h (functions)
##### Hooks

Imagine you are organizing a concert. The main event is the band playing music, which happens continuously. However, you want to add some special effects during the concert, like fireworks, light shows, or audience interactions.

In this metaphor:

The main loop is the band playing music continuously.
Hooks are like special effects you want to add to the concert. They are additional functions that get executed during the main event.
In the context of mlx, hooks allow you to add your own functions to the main loop execution of the program. These functions get executed every frame, just like special effects happening during the concert.

For example:

Key Hook: This is like a special effect triggered when someone in the audience presses a specific button. You can set a function to be called when a key is pressed.
Resize Hook: This is like adjusting the stage size during the concert. You can set a function to handle window resizing.
Generic Hook: This is like a recurring special effect that happens every frame, such as a light show that runs continuously.
However, you can only set one specialized hook (like key or resize hook) at a time. You cannot have multiple specialized hooks. But you can have multiple generic hooks running simultaneously.

##### Images and textures

1. **Texture**:
   - Imagine a **texture** as a **patterned fabric**. This fabric has a design or pattern on it, but you can't directly paint on it. It's like a pre-made design that you can use to cover something else.
   - In MLX, a texture is a pre-defined set of pixel data that you can use to create images, but you don't directly manipulate the texture itself.

2. **Image**:
   - An **image** is like a **blank canvas**. You can paint on this canvas, add colors, and create your own designs. It's something you can directly manipulate and change.
   - In MLX, an image is a buffer where you can set individual pixels, draw shapes, and create your own graphics.

### Managing Textures and Images in MLX

1. **Converting Texture to Image**:
   - To use a texture in your painting, you first need to transfer the design from the fabric (texture) onto your canvas (image). This is done using the `mlx_texture_to_image` function.
   - Example:
     ```cpp
     mlx_image_t* image = mlx_texture_to_image(mlx, texture);
     ```

2. **Creating a New Image**:
   - If you want a blank canvas to start painting from scratch, you create a new image using the `mlx_new_image` function.
   - Example:
     ```cpp
     mlx_image_t* image = mlx_new_image(mlx, width, height);
     ```

3. **Setting Pixels on an Image**:
   - To paint on your canvas, you set the color of individual pixels using the `mlx_put_pixel` function.
   - Example:
     ```cpp
     mlx_put_pixel(image, x, y, color);
     ```

4. **Displaying the Image**:
   - Once your painting (image) is ready, you can display it on the wall (window) using the `mlx_image_to_window` function.
   - Example:
     ```cpp
     mlx_image_to_window(mlx, image, x, y);
     ```

- **Texture**: Pre-made design (patterned fabric) that you can't directly paint on.
- **Image**: Blank canvas that you can paint on and manipulate.
- **Conversion**: Use `mlx_texture_to_image` to transfer a texture onto an image.
- **Creation**: Use `mlx_new_image` to create a new blank image.
- **Manipulation**: Use `mlx_put_pixel` to paint on the image.
- **Display**: Use `mlx_image_to_window` to show the image on the screen.


##### Input

Generic Hook + function
The easiest way of detecting continuous keypressing is via a generic hook and then checking if the specific key is down. This is the 'traditional' way of detecting if a key is down even in modern game engines. It provides the quickest feedback and if it's used to, say, move a character, the smoothest result.


##### Shaders
Imagine you are directing a play on stage. The actors are performing their roles, but you want to create different atmospheres and moods for various scenes. To achieve this, you use different lighting setups, backdrops, and special effects.

In this metaphor:
- The **actors** are the objects in your 3D/2D scene.
- **Shaders** are like the lighting setups, backdrops, and special effects that change how the actors (objects) appear on stage.


Shaders are small programs that run on the GPU (Graphics Processing Unit) and determine how the pixels and vertices in your scene are rendered. They control the appearance of objects by calculating the appropriate levels of light, darkness, and color.

1. **Vertex Shaders**: These are like the stage crew adjusting the positions and shapes of the actors. They process each vertex's position and can transform it, for example, by moving it or changing its size.

2. **Fragment (Pixel) Shaders**: These are like the lighting crew who control the color and brightness of each spot on the stage. They determine the color of each pixel, adding effects like shadows, highlights, and textures.

**Shaders in MLX42**

In MLX42, shaders are exposed and compiled into the library for portability. This means you can use predefined shaders to achieve various visual effects without worrying about compatibility issues across different platforms.

Shaders aren't really meant to be used by students but are more there for the convenience of developers. (though some advanced students might make some use of them)

Shaders are converted into a .c appropriate format and then compiled into the library and referenced via a extern global variable appropriately named vert_shader & frag_shader. The reason this is done is to keep the final game/executable portable, that is being able to use it at any given location within a filesystem, while still being easy to work on the shaders instead of having to mess with it in the .c files directly.

##### Rendering (see mlx42_int.h)

Imagine you are organizing a large art exhibition. You have various artworks (images) that need to be displayed in specific locations within the gallery. To manage this efficiently, you need a detailed plan and a system to keep track of everything.

In this metaphor:
- The **gallery** is your rendering context.
- The **artworks** are the images you want to render.
- The **plan** is the data structure that stores information about where and how to display each artwork.


Rendering in computer graphics involves converting 3D/2D data into a visual image on the screen. This process requires managing various components and data structures to ensure everything is displayed correctly.

**Components**

1. **Vertex Array Object (VAO) and Vertex Buffer Object (VBO)**:
   - These are like the blueprint and materials for constructing the display stands for your artworks. The VAO stores the layout of the vertex data, while the VBO holds the actual vertex data.

2. **Shader Program**:
   - This is like the lighting setup in the gallery, determining how each artwork is illuminated and colored.

3. **Hooks and Z-depth Level**:
   - Hooks are like the instructions for special effects or interactions with the artworks. The Z-depth level ensures that artworks are displayed in the correct order, with some appearing in front of or behind others.

4. **Draw Calls and Linked List Queue**:
   - Draw calls are like the instructions for placing each artwork in the gallery. The linked list queue helps manage these instructions efficiently, pointing to the specific image and its instance.

5. **Instances and XYZ Data**:
   - Instances are like the individual copies of an artwork that need to be displayed. The XYZ data specifies the exact position of each instance within the gallery.

6. **Texture Contexts and Capacity**:
   - Texture contexts are like the storage areas for the artworks, keeping track of how many instances can be displayed. The capacity is managed dynamically, similar to how you might rearrange the gallery to accommodate more artworks.

**Summary**

In summary, rendering in MLX42 involves organizing and managing various components to display images correctly on the screen. It's like setting up an art exhibition, where you need a detailed plan and system to ensure each artwork is displayed in the right place, with the right lighting and effects.

Some history: XPM42
https://www.xfree86.org/current/xpm.pdf

#### flood fill

#### make vs cmake

#### X11

#### GLFW

#### why .ber maps?

#### algoritmo para comprobar si el mapa es cerrado

#### cómo estoy trabajando mlx y las otras funciones estoy haciendo relink? 

### Subject
Objetivo: Este proyecto no solo te permitirá añadir una función bastante práctica a tu colección;
también te hará aprender el increíble concepto de las variables estáticas en C.
Una vez superado, no dudes en añadir tu get_next_line() a tu lift.
## Evaluations
## Further study





