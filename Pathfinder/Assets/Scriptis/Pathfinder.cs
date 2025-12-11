using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Pathfinder : MonoBehaviour
{
    public GameObject Tile;

    public int Width = 20;
    public int Height = 20;
    public float Spacing = 2.05f;

    // Start is called before the first frame update
    void Start()
    {
        for (int y = 0; y < Height; y++)
        {
            for (int x = 0; x < Width; x++)
            {
                Instantiate(Tile, new Vector3(x * Spacing - Width / 2 * Spacing, y * Spacing - Height / 2 * Spacing, 0), Tile.transform.rotation);
            }
        }

        if (Height < Width)
        {
            Camera.main.transform.position = new Vector3(0, 0, -Width * Spacing);
        }
        else
        {
            Camera.main.transform.position = new Vector3(0, 0, -Height * Spacing);
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
