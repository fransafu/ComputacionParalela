class AddColumnLibreDisponibilidadDocentes < ActiveRecord::Migration[5.0]
  def change
    add_column :disponibilidad_docentes, :libre, :boolean, default: true
  end
end
