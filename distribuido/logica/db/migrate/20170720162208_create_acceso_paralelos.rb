class CreateAccesoParalelos < ActiveRecord::Migration[5.0]
  def change
    create_table :acceso_paralelos do |t|
      t.boolean :disponible, default: true

      t.timestamps
    end
  end
end
