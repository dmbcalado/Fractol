<h1><em>Fract-ol</em><strong><em> (grade : ??)</em></strong></h1>
<div align="center"><br /><img src="https://user-images.githubusercontent.com/76601369/110706242-77158d00-81ef-11eb-8085-5da6f0988553.jpg" alt="https://user-images.githubusercontent.com/76601369/110706242-77158d00-81ef-11eb-8085-5da6f0988553.jpg" width="400" height="200" /></div>
<p><strong>This project has the goal of creating a program with a graphical library (minilibx), by creating, handling and refreshing the image.</strong></p>
<p><strong>Important: <p>To run the program you first need to install X11, XShm extension and libbsd-dev package, by typing in the terminal:</strong></p>
<p><strong>sudo apt-get install gcc make xorg libxext-dev libbsd-dev</strong></p>
<p><strong>After that, enter the folder mlx_linux and run ./configure</strong></p>
<p>*This program is built to run on Linux and most of the utilities in MacOs will fail since the int sent by each key has a different value.*</p>
<p>In the mandatory part, the task given is to have a program that would be able to:</p>
<ul style="list-style-type: square;">
<li>Offer the option of the chosing both <strong>Mandelbot</strong> and <strong>Julia sets</strong>.</li>
<li>Offer the option to zoom on mouse wheel.</li>
<li>Be able to exit the program by pressing ESC or by clicking in the cross(x) in the window.</li>
</ul>
<p>So the way i aproached the problem is let the user choose by typing:</p>
<p><strong>1 - $&gt; ./fractol mandelbrot</strong></p>
<p><strong>2 - $&gt; ./fractol julia</strong></p>
<p><strong>3 - $&gt;./fractol julia (<span style="color: #0000ff;">double</span> x) (<span style="color: #0000ff;"><em>double</em></span> y)</strong></p>
<p><strong>Results:</strong></p>
<div align="center"><br /><img src="https://user-images.githubusercontent.com/99777188/193884765-f578d346-c4f2-4c4f-9dfb-ac5cc841b6e6.png" width="630" height="600" /></div>
<div align="center"><br /><img src="https://user-images.githubusercontent.com/99777188/193886379-44997b70-9ac6-448c-957b-2be10803786e.png" width="600" height="600" /></div>
<div align="center"><br /><img src="https://user-images.githubusercontent.com/99777188/193886687-47013174-1cfa-48ac-b8c2-055083aefd46.png" width="600" height="600" /></div>
<p>The first image shows the Mandelbrot set with 300 iterations. The second one, The Julia set with c = -0.78i with 300 iterations, and the third image is deep inside one Julia set choosed by the mouse click, once again with 300 iterations. </p>
<p><strong>Some extra features I added:</strong></p>
<ul style="list-style-type: square;">
<li>Ability to <strong>move</strong> the image with <strong>W A S D</strong> or the <strong>arrow keys</strong>. (increases the speed with the zoom).</li>
<li><strong>Increase or decrease</strong> the iterations with the <strong>'+'</strong> and <strong>'-'</strong> keys on the numpad.</li>
<li>For the Mandelbrot set, choose where to zoom by mouse clicking the spot in the image (once). For the Julia set, change the c parameter by mouse clicking the new values. (The new value will be displayed on the terminal).</li>
<li>A <strong>night mode</strong> by <strong>pressing 'N'</strong>.(and rechange to normal mode by re-pressing it).</li>
</ul>
<p>I could go into details what's the mathematics behind each set but nowadays you can find it almost everywhere. If you have literally zero insights, I would however recomend you the numberphile videos (since i really enjoy them and probably you will understand at least the concepts),</p>
<p>There is of course some points in the job that could be better. The first great feature that i can think of is a scalable with zoom axis, to really be able to get a more mathematical aproach on this program.</p>
<p>The second thing that i can think of is to really be able to zoom where the mouse stands, that would have been great however i couldn't understand how to do so on minilibx library.</p>
<p>As my grade i got ??, getting full grade on the mandatory  part and a bit of the bonus part.</p>
<div align="center"><br /><img src="https://user-images.githubusercontent.com/99777188/193395212-77b31dcb-76cb-478f-8024-16e6b4960e28.png" width="800" height="230" /></div>
