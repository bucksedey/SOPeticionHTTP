/*
Grupo: 4CV1
Flores Anzurez Marco Antonio

Aquí hay un ejemplo de cómo hacer que un programa realice una solicitud HTTP (no HTTPS, por lo que sin SSL) 
a una página web. con la biblioteca libcurl. 
Ten en cuenta que necesitarás tener libcurl instalado en tu sistema para compilar y ejecutar este código.
*/
#include <stdio.h>
#include <curl/curl.h>

int main(void) {
    // Inicializa una variable puntero CURL y una variable para almacenar el código de retorno.
    CURL *curl;
    CURLcode res;

    // Inicializa la biblioteca libcurl.
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Inicializa un nuevo objeto CURL fácil.
    curl = curl_easy_init();
    if(curl) {
        // Configura la URL de la solicitud HTTP.
        curl_easy_setopt(curl, CURLOPT_URL, "http://escom.com");

        /* Sigue la redirección, si hay una */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        /* Realiza la solicitud, res almacenará el código de retorno */
        res = curl_easy_perform(curl);

        /* Comprueba si hubo errores */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() falló: %s\n",
                    curl_easy_strerror(res));
        
        /* Siempre limpia */
        curl_easy_cleanup(curl);
    }

    // Limpia y cierra la biblioteca libcurl.
    curl_global_cleanup();

    return 0;
}
